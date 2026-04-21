//
// Created by Alexander Dickhans on 4/20/26.
//

#include "player.h"

#include <stdlib.h>

#include "utils/utils.h"

struct _player {
    FactoryNode *head;
    int current_balance;
};

Player *create_player(void) {
    Player *player = malloc(sizeof(Player));

    if (player) {
        player->head = NULL;
        player->current_balance = 0;
    }

    return player;
}

void click_pickle(Player *player) {
    if (player) {
        player->current_balance++;
    }
}

int get_score_player(const Player *player) {
    if (player) {
        return player->current_balance;
    }
    return -1;
}

void print_player_status(Player *player) {
    if (player) {
        printf("Current Balance: %d pickles. Current Factories: \n", player->current_balance);
        const FactoryNode *next = player->head;

        float total_production = 0;
        int count = 0;
        while (next) {
            // print_factory(next);
            total_production += get_factory_rate(next);
            count++;
            next = next_factory(next);
        }

        printf("%d picklers with a total Production Rate: %.1f\n", count, total_production);
    }
}

void print_all_factories(Player *player) {
    if (player) {
        const FactoryNode *next = player->head;

        while (next) {
            print_factory(next);
            next = next_factory(next);
        }
    }
}

void update_score(Player *player) {
    if (player) {
        FactoryNode *next = player->head;
        while (next) {
            const int res = update_factory(next);
            player->current_balance += res;
            next = next_factory(next);
        }
    }
}

int buy_factory(Player *player, const FactoryPrototype *prototype) {
    // Check for NULL
    if (player) {
        // Check balance
        if (player->current_balance < prototype->cost) {
            return -1;
        }

        FactoryNode *new_factory = create_factory(prototype, player->head);

        if (!new_factory) {
            return -2;
        }

        player->head = new_factory;

        player->current_balance -= prototype->cost;

        return 0;
    }

    return -2;
}

void destroy_player(Player *player) {
    if (player) {
        destroy_factories(player->head);
        free(player);
    }
}

void test_player() {

}
