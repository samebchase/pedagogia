#include <limits.h>
#include <stddef.h>

/*
 -(INT_MAX / 2) shall henceforth be used as a large negative integer,
 to indicate an invalid array index.
*/

int linear_search(int *array, size_t length, int element) {
    for (int i = 0; i < length; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -(INT_MAX / 2);
}

int linear_search_rec(int *array, size_t length, int element) {
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

int binary_search(int *array, int element,
                  size_t start_index, size_t end_index) {

    size_t middle_index   = (end_index - start_index) / 2  +  start_index;
    size_t middle_element = array[middle_index];

    if (element == middle_element) {
        return middle_index;
    }

    if (start_index == middle_index || end_index == middle_index) {
        return -(INT_MAX / 2);
    }

    if (element < middle_element) {
        return binary_search(array, element, start_index, middle_index - 1);
    }

    else if (element > middle_element) {
        return binary_search(array, element, middle_index + 1, end_index);
    }
}
