#include <math.h>
#include <stdio.h>

#include "util.h"

void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a  = *b;
    *b  = tmp;
}

void initialise_random_seed() {
    static int initialised = 0;
    if (!initialised) {
        srand(time(NULL));
        initialised = 1;
    }
}

int random_integer(int start, int end) {
    initialise_random_seed();

    float normalised_random_value = rand() / ((float) RAND_MAX + 1);
    int   range_width             = end - start + 1;
    float scaled_value            = range_width * normalised_random_value;
    int   retval                  = floor((float) scaled_value + start);

    return retval;
}

int* generate_array(size_t length) {
    int *array = malloc(sizeof(int) * length);
    return array;
}

void randomise_array(int *array, size_t length,
                     int interval_begin, int interval_end) {
    for (size_t i = 0; i < length; ++i) {
        array[i] = random_integer(interval_begin, interval_end);
    }
}
