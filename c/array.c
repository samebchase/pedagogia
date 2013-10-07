#include "array.h"

void print_array(int *array, int length) {
    printf("[");
    
    for (int i = 0; i < length - 1; i++) {
        printf("%d, ", array[i]);
    }
    
    printf("%d", array[length - 1]);
    printf("]");
    printf("\n");
}

/*

  WARNING: print_array_rec() is proof-of-concept code. See
  print_array() for a better way of doing the same thing.

*/

void print_array_rec_helper(int *array, int length) {
    if (length <= 0) {
        return;
    }

    else if (length == 1) {
        printf("%d", *array);
    }

    else {
        printf("%d, ", *array);
        print_array_rec_helper(array + 1, length - 1);
    }
}

void print_array_rec(int *array, int length) {
    printf("[");
    print_array_rec_helper(array, length);
    printf("]\n");
}

void reverse_array(int *array, int length) {
    for (int i = 0; i < length / 2; ++i) {
        swap(&array[i], &array[length - 1 - i]);
    }
}

void reverse_array_rec(int *array, int length);

void left_rotate_array(int *array, int length) {
    left_rotate_subarray(array, length, 0, length - 1);
}

void left_rotate_subarray(int *array, int length, int start, int end) {
    assert(start <= end);
    int subarray_last_element = array[end];

    for (int i = end; i > start; --i) {
        array[i] = array[i - 1];
    }

    array[start] = subarray_last_element;
}
