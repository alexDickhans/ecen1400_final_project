//
// Created by Alexander Dickhans on 4/18/26.
//

#include <stdio.h>

#include "utils/help.h"

void print_general_help(void) {
    printf("\n");
    printf("Commands (single key, raw terminal):\n");
    printf("  h  help — print this menu\n");
    printf("  u  unit tests\n");
    printf("  s  show factories — list factories you own\n");
    printf("  p  pickle — manual click; earn pickles\n");
    printf("  x  exit — quit the game\n");
    printf("  c, d, ...  buy a factory — keys match the shop lines printed each turn\n");
    printf("\n");
}
