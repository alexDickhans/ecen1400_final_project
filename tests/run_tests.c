//
// Unit tests for factory, factory_shop, and player.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "factory/factory.h"
#include "factory/factory_shop.h"
#include "player.h"

static int g_failures;

#define EXPECT(cond, msg)                                                              \
    do {                                                                               \
        if (!(cond)) {                                                                 \
            fprintf(stderr, "FAIL %s:%d — %s\n", __FILE__, __LINE__, msg);             \
            g_failures++;                                                              \
        }                                                                              \
    } while (0)

#define EXPECT_INT_EQ(a, b, msg) EXPECT((a) == (b), msg)
#define EXPECT_PTR_NULL(p, msg) EXPECT((p) == NULL, msg)
#define EXPECT_PTR_NON_NULL(p, msg) EXPECT((p) != NULL, msg)

static void test_factory_create_and_chain(void) {
    const FactoryPrototype proto = {"alpha", 10, 2.5};
    FactoryNode *head = NULL;
    FactoryNode *a = create_factory(&proto, head);
    EXPECT_PTR_NON_NULL(a, "create_factory should allocate");
    EXPECT(get_factory_rate(a) == 2.5f, "rate should match prototype");
    EXPECT_PTR_NULL(next_factory(a), "first node next should be head (NULL)");

    const FactoryPrototype proto2 = {"beta", 3, 1.0};
    FactoryNode *b = create_factory(&proto2, a);
    EXPECT_PTR_NON_NULL(b, "second factory allocates");
    EXPECT_PTR_NON_NULL(next_factory(b), "second should point to first");
    EXPECT(get_factory_rate(b) == 1.0f, "second factory rate");
    EXPECT(get_factory_rate(next_factory(b)) == 2.5f, "chain preserves first node rate");
    print_factory(b);
    print_factory(next_factory(b));

    destroy_factories(b);
}

static void test_factory_update_accumulator(void) {
    const FactoryPrototype half = {"half", 0, 0.5};
    FactoryNode *f = create_factory(&half, NULL);
    EXPECT_INT_EQ(update_factory(f), 0, "first half tick yields 0 whole pickles");
    EXPECT_INT_EQ(update_factory(f), 1, "second half tick completes one pickle");
    EXPECT_INT_EQ(update_factory(f), 0, "pattern continues");
    destroy_factories(f);

    const FactoryPrototype one = {"one", 0, 1.0};
    FactoryNode *g = create_factory(&one, NULL);
    EXPECT_INT_EQ(update_factory(g), 1, "rate 1.0 yields one per tick");
    EXPECT_INT_EQ(update_factory(g), 1, "stable one per tick");
    destroy_factories(g);
}

static void test_factory_get_rate_null(void) {
    EXPECT(get_factory_rate(NULL) == -1.0f, "NULL factory rate is -1");
    EXPECT_PTR_NULL(next_factory(NULL), "NULL next_factory");
}

static void test_factory_shop_options(void) {
    FactoryPrototype opts[] = {
        {"A", 1, 0.1},
        {"B", 2, 0.2},
        {"C", 4, 0.4},
    };
    FactoryShop *shop = create_factory_shop(opts, 3);
    EXPECT_PTR_NON_NULL(shop, "shop allocates");

    EXPECT_PTR_NULL(get_option_factory_shop(NULL, 'a', 'a'), "NULL shop");
    EXPECT_PTR_NULL(get_option_factory_shop(shop, 'a', '`'), "before range");
    EXPECT_PTR_NULL(get_option_factory_shop(shop, 'a', 'd'), "after range");

    FactoryPrototype *p0 = get_option_factory_shop(shop, 'a', 'a');
    FactoryPrototype *p1 = get_option_factory_shop(shop, 'a', 'b');
    EXPECT_PTR_NON_NULL(p0, "valid index a");
    EXPECT_PTR_NON_NULL(p1, "valid index b");
    EXPECT_INT_EQ(p0->cost, 1, "first option cost");
    EXPECT_INT_EQ(p1->cost, 2, "second option cost");
    EXPECT(fabs(p1->rate - 0.2) < 1e-6, "second option rate");

    print_options_factory_shop(shop, 'a');

    destroy_factory_shop(shop);
}

static void test_factory_shop_empty(void) {
    /* len 0 with a non-null prototype pointer avoids memcpy(NULL, ..., 0) (undefined). */
    FactoryPrototype dummy = {"none", 0, 0.0};
    FactoryShop *shop = create_factory_shop(&dummy, 0);
    EXPECT_PTR_NON_NULL(shop, "empty shop still allocates shell");
    EXPECT_PTR_NULL(get_option_factory_shop(shop, 'a', 'a'), "no options when len is 0");
    destroy_factory_shop(shop);
}

static void test_player_click_and_score(void) {
    Player *p = create_player();
    EXPECT_PTR_NON_NULL(p, "player allocates");
    EXPECT_INT_EQ(get_score_player(p), 0, "initial score 0");
    click_pickle(p, 1);
    click_pickle(p, 1);
    EXPECT_INT_EQ(get_score_player(p), 2, "clicks add to balance");
    EXPECT_INT_EQ(get_score_player(NULL), -1, "NULL player score");
    destroy_player(p);
}

static void test_player_buy_factory(void) {
    Player *p = create_player();
    const FactoryPrototype cheap = {"mini", 5, 1.0};
    for (int i = 0; i < 4; i++) {
        click_pickle(p, 1);
    }
    EXPECT_INT_EQ(buy_factory(p, &cheap), -1, "cannot afford");
    destroy_player(p);

    p = create_player();
    for (int i = 0; i < 10; i++) {
        click_pickle(p, 1);
    }
    EXPECT_INT_EQ(get_score_player(p), 10, "saved up");
    const FactoryPrototype f = {"plant", 7, 2.0};
    EXPECT_INT_EQ(buy_factory(p, &f), 0, "purchase succeeds");
    EXPECT_INT_EQ(get_score_player(p), 3, "balance after purchase");
    print_player_status(p);
    print_all_factories(p);

    update_score(p);
    EXPECT_INT_EQ(get_score_player(p), 5, "production adds 2 pickles");

    destroy_player(p);
}

static void test_player_buy_null_player(void) {
    const FactoryPrototype f = {"x", 1, 1.0};
    EXPECT_INT_EQ(buy_factory(NULL, &f), -2, "NULL player");
}

int main(void) {
    g_failures = 0;

    test_factory_create_and_chain();
    test_factory_update_accumulator();
    test_factory_get_rate_null();
    test_factory_shop_options();
    test_factory_shop_empty();
    test_player_click_and_score();
    test_player_buy_factory();
    test_player_buy_null_player();

    if (g_failures == 0) {
        puts("All tests passed.");
        return 0;
    }
    fprintf(stderr, "%d test assertion(s) failed.\n", g_failures);
    return 1;
}
