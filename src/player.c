//
// Created by Alexander Dickhans on 4/20/26.
//

#include "player.h"

#include <stdlib.h>
#include <stdio.h>

#include "utils/utils.h"

struct _player {
    FactoryNode *head; // Linked list for auto allocation size
    int current_balance;
};

Player *create_player(void) {
    // Allocate memory
    Player *player = malloc(sizeof(Player));

    // Check for null
    if (player) {
        // Create empty player
        player->head = NULL;
        player->current_balance = 0;
    }

    return player;
}

void click_pickle(Player *player, const int n) {
    // Check null
    if (player) {
        player->current_balance += n;
    }
}

int get_score_player(const Player *player) {
    // Check null
    if (player) {
        return player->current_balance;
    }
    return -1;
}

void print_player_status(const Player *player) {
    // check null
    if (player) {
        // Print info
        printf("Current Balance: %d pickles. Current Factories: \n", player->current_balance);

        // Calculate total production
        const FactoryNode *next = player->head;

        float total_production = 0;
        int count = 0;
        while (next) {
            // print_factory(next);
            total_production += get_factory_rate(next);
            count++;
            next = next_factory(next);
        }

        // Print total production
        printf("%d picklers with a total Production Rate: %.1f\n", count, total_production);
    }
}

void print_all_factories(const Player *player) {
    // Check for null
    if (player) {
        // Loop through all objects printing the factory for each
        const FactoryNode *next = player->head;

        while (next) {
            print_factory(next);
            next = next_factory(next);
        }
    }
}

void update_score(Player *player) {
    // Check null
    if (player) {
        // Loop through all factories
        FactoryNode *next = player->head;
        while (next) {
            const int res = update_factory(next);
            if (res < 0) {
                return;
            }
            player->current_balance += res;
            next = next_factory(next);
        }
    }
}

int buy_factory(Player *player, const FactoryPrototype *prototype) {
    // Check for NULL
    if (player && prototype) {
        // Check balance
        if (player->current_balance < prototype->cost) {
            return -1;
        }

        // Links new factory at beginning
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
    // Check for null
    if (player) {
        destroy_factories(player->head);
        free(player);
    }
}
