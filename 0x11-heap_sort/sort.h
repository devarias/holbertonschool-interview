#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void down(int *array, int size, int i, int size_array);
void swap(int *a, int *b);
int check(int *array, int size);

#endif
