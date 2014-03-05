#pragma once

#include <stdio.h>
#include <assert.h>

#include "../util/util.h"

/*

  Array operations

*/

void insert(int *array,   int length,
            int insertee, int position);

void print_array(int *array, int length);

void reverse_array(int *array, int length);

void left_rotate_array(int *array, int length);

void left_rotate_subarray(int *array, int length,
                          int start, int end);

void print_array_rec(int *array, int length);
