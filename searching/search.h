#pragma once

#include "../arrays/array.h"

int linear_search(int *array, int length, int element);

int linear_search_rec(int *array, int length, int element);

int binary_search(int *array, int element, size_t start, size_t end);
