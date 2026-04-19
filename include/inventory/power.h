//
// Created by Alexander Dickhans on 4/18/26.
//

#ifndef FINAL_PROJECT_POWER_H
#define FINAL_PROJECT_POWER_H

typedef struct _power_grid PowerGrid;

PowerGrid* create_power_grid(void);

void destroy_power_grid(PowerGrid* grid);

#endif // FINAL_PROJECT_POWER_H
