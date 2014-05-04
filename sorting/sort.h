#pragma once

#include "../arrays/array.h"
#include "../util/util.h"

bool is_sorted(int *array, size_t length);

void insertion_sort(int *array, size_t length);

void selection_sort(int *array, size_t length);

void bubble_sort(int *array, size_t length);

// void quicksort(int *array, size_t length);

int* merge_arrays(int *array_a, size_t a_length, int *array_b, size_t b_length);

void merge_sort(int *array, size_t length);

void heap_sort(int *array, size_t length);
