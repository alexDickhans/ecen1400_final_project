//
// Created by Alexander Dickhans on 4/20/26.
//

#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H

#include "factory/factory.h"

typedef struct _player Player;

Player* create_player(void);

void click_pickle(Player* player);

int get_score_player(const Player* player);

void print_player_status(Player* player);

void print_all_factories(Player* player);

void update_score(Player* player);

/**
 *
 * @param player The player to buy the factory for
 * @param prototype The factory that is desired
 * @return 0 if success, -1 if insufficient funds, -2 for missed allocation/unexpected NULL
 */
int buy_factory(Player* player, const FactoryPrototype* prototype);

void destroy_player(Player* player);

#endif //FINAL_PROJECT_PLAYER_H
