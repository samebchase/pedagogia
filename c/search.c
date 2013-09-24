#include <limits.h>
#include "array.h"

int linear_search(int *array, int length, int element) {
    for (int i = 0; i < length; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    /* A large enough negative integer. */
    return -(INT_MAX / 2);
}

int linear_search_rec(int *array, int length, int element) {
    if (length == 0) {
        return -(INT_MAX / 2);
    }

    if (length != 0 && *array == element) {
        return 0;
    }

    else {
        return 1 + linear_search_rec(array + 1, length - 1, element);
    }
}

int binary_search(int *array, int length);
