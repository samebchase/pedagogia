#pragma once

#include "util.h"

int is_sorted(int *array, size_t length);

void insertion_sort(int *array, size_t length);

void selection_sort(int *array, size_t length);

void bubble_sort(int *array, size_t length);

// void quicksort(int *array, size_t length);

void merge_sort(int *array, size_t length);

void heap_sort(int *array, size_t length);
