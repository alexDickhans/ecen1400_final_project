//
// Created by Alexander Dickhans on 4/18/26.
//

#include <stdbool.h>
#include <stdio.h>
#include "player.h"
#include "utils/utils.h"
#include "factory/factory.h"
#include "factory/factory_shop.h"
#include <poll.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "utils/help.h"

int main(void) {
    bool running = true;
    const char factory_menu_start_char = 'c';

    struct termios orig_termios;

    // Call this at the very beginning of your program, before the while loop
    enable_raw_mode(&orig_termios);

    const FactoryPrototype factories[] = {
        {"Jr. Pickler", 15, 0.1}, {"Sr. Pickler", 100, 1.0}, {"Pickle Farm", 1100, 8.0},
        {"Pickle Factory", 15000, 100.0}, {"Pickle World", 120000, 1000.0}
    };

    FactoryShop *factory_shop = create_factory_shop(factories, 5);

    Player *player = create_player();

    // Check for missed allocation
    if (!factory_shop || !player) {
        destroy_factory_shop(factory_shop);
        destroy_player(player);
        printf("Unable to allocate game elements.\n");
        return 0;
    }

    // Generate random numbers
    srand(time(NULL));

    // Create poll object for easier use
    struct pollfd character_poll = {STDIN_FILENO, POLLIN, 0};

    // Infinite loop while running
    while (running) {
        bool golden_pickle_mode = rand() % 100 < 10; // 10% chance of being true

        // Show golden pickle message
        if (golden_pickle_mode) {
            printf("Golden Pickle Mode, press (z) to pick up %d pickles\n", 50+get_score_player(player)/3);
        }

        // Print player options and status
        print_player_status(player);
        printf("Options: ");
        printf("(h)elp: print help menu, (s)how factories, (p)ickle: Pickle!, e(x)it\n");
        print_options_factory_shop(factory_shop, factory_menu_start_char);

        // Poll for characters
        const int ret = poll(&character_poll, 1, 1000);

        clear_screen();

        if (ret > 0) {
            // Read a character from the command line
            char c;

            const ssize_t read_ret = read(STDIN_FILENO, &c, 1);

            // Check for errors
            if (read_ret < 0) {
                printf("IO error, exiting\n");
                running = false;
                break;
            }

            // Switch based on the input character
            switch (c) {
                case 'p':
                    click_pickle(player, 1);
                    break;
                case 'x':
                    // Exit
                    running = false;
                    break;
                case 'h':
                    print_general_help();
                    break;
                case 'z':
                    // Golden pickle mode
                    if (golden_pickle_mode) {
                        click_pickle(player, 50 + get_score_player(player)/3);
                    } else {
                        printf("Golden Pickle Mode is not active\n");
                    }
                    break;
                case 's':
                    print_all_factories(player);
                    break;
                default: {
                    // Check for the factory prototype selection
                    const FactoryPrototype *factory_prototype = get_option_factory_shop(
                        factory_shop, factory_menu_start_char, c);

                    // Check for null
                    if (factory_prototype) {
                        // Buy the factory
                        const int res = buy_factory(player, factory_prototype);

                        // Check for error in purchase
                        switch (res) {
                            case 0:
                                printf("Bought: %s\n", factory_prototype->name);
                                break;
                            case -1:
                                printf("Unable to purchase %s, inadequate pickles.\n", factory_prototype->name);
                                break;
                            default:
                                printf("Error, exiting\n");
                                running = false;
                        }
                    } else {
                        printf("unknown command, try (h) for the help menu.\n");
                    }
                    break;
                }
            }
        } else if (ret == 0) {
            // Update the score every second
            update_score(player);
        } else {
            // Return gracefully on error
            printf("Error handling input, exiting ...\n");
            running = false;
        }
    }

    // Clean exit
    show_score(get_score_player(player));
    disable_raw_mode(&orig_termios);
    destroy_player(player);
    destroy_factory_shop(factory_shop);

    return 0;
}
