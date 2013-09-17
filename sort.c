#include "sort.h"
#include "array.h"
#include "util.h"

int is_sorted(int *array, int length) {
    int sorted_flag = 1;

    for (int i = 0; i < length - 1; ++i) {
        if (array[i + 1] < array[i]) {
            sorted_flag = 0;
        }
    }

    return sorted_flag;
}

/*
  Take an element, put it in a sorted subarray.
*/

void insertion_sort(int *array, int length) {
    for (int i = 1; i < length; ++i) {
        for (int j = i; j > 0; --j) {
            if (array[j] < array[j - 1]) {
                swap(&array[j], &array[j - 1]);
            }
        }
    }
}

int find_minimum_index(int *array, int length,
                       int start_index, int end_index) {
    assert(end_index < length);
    int min_index = start_index;

    for (int i = start_index; i <= end_index; ++i) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }

    return min_index;
}

void selection_sort(int *array, int length) {
    int i, min_index;
    for (i = 0; i < length - 1; ++i) {
        min_index = find_minimum_index(array, length, i, length - 1);
        swap(&array[i], &array[min_index]);
    }
}
