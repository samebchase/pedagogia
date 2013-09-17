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
    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0; --j) {
            if (array[j] < array[j - 1]) {
                swap(&array[j], &array[j - 1]);
            }
        }
    }
}

void selection_sort(int *array, int length) {
}
