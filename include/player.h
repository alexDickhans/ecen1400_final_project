//
// Created by Alexander Dickhans on 4/20/26.
//

#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H

#include "factory/factory.h"

/**
 * Struct to store player progress such as the current balance of the player and the factories that have been purchased
 */
typedef struct _player Player;

/**
 * Creates a player with blank attributes, returns NULL in the case of an allocation failure
 * @return Returns a new player that has blank attributes
 */
Player* create_player(void);

/**
 * Add to a player's score
 * @param player Player to add pickles to
 * @param n Number of pickles to add to player's balance
 */
void click_pickle(Player* player, int n);

/**
 * Get the score of the player
 *
 * @param player Player ADT to get the score of
 * @return the current score of the player, -1 if error
 */
int get_score_player(const Player* player);

/**
 * Print current player status including balance
 *
 * @param player Player object
 */
void print_player_status(const Player* player);

/**
 * Print all the current factories that a player owns
 *
 * @param player Player object
 */
void print_all_factories(const Player* player);

/**
 * Called to refresh the score of the player, recalculating from all the factories the player owns
 * @param player Player object
 */
void update_score(Player* player);

/**
 *
 * @param player The player to buy the factory for
 * @param prototype The factory that is desired
 * @return 0 if success, -1 if insufficient funds, -2 for missed allocation/unexpected NULL
 */
int buy_factory(Player* player, const FactoryPrototype* prototype);

/**
 * Safely destroy a player object, freeing all memory
 *
 * @param player Player to destroy
 */
void destroy_player(Player* player);

#endif //FINAL_PROJECT_PLAYER_H
