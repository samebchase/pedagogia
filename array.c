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
