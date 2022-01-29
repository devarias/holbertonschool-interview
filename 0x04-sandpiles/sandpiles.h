#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

int stable(int grid[3][3]);
void print_gridv2(int grid[3][3]);
void sum_grid(int grid1[3][3], int grid2[3][3]);
void topple(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif