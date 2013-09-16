#include <stdio.h>
#include "util.h"

void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a  = *b;
    *b  = tmp;
}

void print_array(int *array, int length) {
    printf("[");
    
    for (int i = 0; i < length - 1; i++) {
        printf("%d, ", array[i]);
    }
    
    printf("%d", array[length - 1]);
    printf("]");
    printf("\n");
}
