#ifndef MAIN_h
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void sift_down(int *array, int root, int end);
void swap(int *a, int *b);

#endif
