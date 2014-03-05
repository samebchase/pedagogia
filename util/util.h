#pragma once

#include <math.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

/*

  Utilities, that don't fit anywhere else.

*/


/* A simple swap function for integers */

void swap(int *, int *);

int* generate_array(size_t length);

int random_integer(int start, int end);

void randomise_array(int *array, size_t length,
                     int interval_begin, int interval_end);


    
