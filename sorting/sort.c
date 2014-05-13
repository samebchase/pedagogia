#include "../arrays/array.h"
#include "sort.h"

bool is_sorted(int *array, size_t length) {
    for (size_t idx = 0; idx < length - 1; ++idx) {
        if (array[idx + 1] < array[idx]) {
            return false;
        }
    }
    return true;
}

void insertion_sort(int *array, size_t length) {
    for (size_t idx = 1; idx < length; ++idx) {
        for (int jdx = idx; jdx > 0; --jdx) {
            if (array[jdx] < array[jdx - 1]) {
                swap(&array[jdx], &array[jdx - 1]);
            }
        }
    }
}

int minimum_element_index(int *array, size_t length,
                          int start_index, int end_index) {
    assert(end_index < length);
    int min_index = start_index;

    for (size_t i = start_index; i <= end_index; ++i) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }

    return min_index;
}

void selection_sort(int *array, size_t length) {
    size_t i, min_index;
    for (i = 0; i < length - 1; ++i) {
        min_index = minimum_element_index(array, length, i, length - 1);
        swap(&array[i], &array[min_index]);
    }
}

void bubble_sort(int *array, size_t length) {
    for (bool swaps_have_occured = true; swaps_have_occured; ) {
        swaps_have_occured = false;
        for (size_t i = 0; i < length - 1; ++i) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                swaps_have_occured = true;
            }
        }
    }
}

int* copy_array(int *array, size_t length) {
    int *copied_array = malloc(sizeof(int) * length);
    for (int idx = 0; idx < length; ++idx) {
        copied_array[idx] = array[idx];
    }
    return copied_array;
}

void set_extremal_elements(int *array, size_t length, int *max, int *min) {
    int current_element, current_maximum, current_minimum;
    current_maximum = current_minimum = array[0];

    for (int idx = 0; idx < length; ++idx) {
        current_element = array[idx];
        if (current_element > current_maximum) {
            current_maximum = current_element;
        }
        if (current_element < current_minimum) {
            current_minimum = current_element;
        }
    }
    *max = current_maximum;
    *min = current_minimum;
}

size_t number_in_range_to_index(int number, int minimum, int maximum) {
    assert(number <= maximum);
    int idx = number - minimum;
    return idx;
}

int index_to_number_in_range(size_t idx, int minimum, int maximum) {
    int number = minimum + idx;
    assert((number >= minimum) && (number <= maximum));
    return number;
}

void counting_sort(int *array, size_t length) {

    int maximum, minimum;
    set_extremal_elements(array, length, &maximum, &minimum);

    int counting_array_length = maximum - minimum + 1;
    int *counting_array = calloc(counting_array_length, sizeof(int));

    for (int idx = 0; idx < length; ++idx) {
        int current_number = array[idx];
        int translated_index = number_in_range_to_index(current_number, minimum, maximum);
        counting_array[translated_index]++;
    }

    int a_idx, c_idx;
    a_idx = c_idx = 0;

    while ((c_idx < counting_array_length) && (a_idx < length)) {
        for (int j = 0; j < counting_array[c_idx]; ++j, ++a_idx) {
            array[a_idx] = index_to_number_in_range(c_idx, minimum, maximum);
        }
        ++c_idx;
    }
}

int* merge_sort_aux(int *array, size_t start_idx, size_t end_idx) {
    if (end_idx - start_idx + 1 <= 1) {
        return array;
    }
    else {
        size_t mid_idx = (end_idx - start_idx + 1) / 2;
        size_t left_subarray_length  = mid_idx - start_idx;
        size_t right_subarray_length = end_idx - mid_idx + 1;

        int *left_subarray  = merge_sort_aux(array, 0, left_subarray_length - 1);
        int *right_subarray = merge_sort_aux(array + mid_idx, 0, right_subarray_length - 1);

        return merge_arrays(left_subarray,  left_subarray_length,
                            right_subarray, right_subarray_length);
    }
}

void merge_sort(int *array, size_t length) {
    int *sorted_array = merge_sort_aux(array, 0, length - 1);
    for (size_t idx = 0; idx < length; ++idx) {
        array[idx] = sorted_array[idx];
    }
    free(sorted_array);
}

int* merge_arrays(int *array_a, size_t a_length, int *array_b, size_t b_length) {
    size_t merged_array_length = (a_length + b_length);
    int *merged_array = malloc(sizeof(int) * merged_array_length);
    size_t a_idx, b_idx, m_idx;
    a_idx = b_idx = m_idx = 0;

    // We compare two elements from array_a and array_b and copy the
    // smaller one into merged_array, until one of the array indices
    // (a_idx or b_idx) has reached the end of array_a or array_b
    // respectively.

    while (a_idx < a_length && b_idx < b_length) {
        if (array_a[a_idx] <= array_b[b_idx]) {
            merged_array[m_idx++] = array_a[a_idx++];
        }
        else {
            merged_array[m_idx++] = array_b[b_idx++];
        }
    }

    // Now we find out which array has been fully copied into
    // merged_array and copy the remaining subarray of the array that
    // has not been copied into merged_array

    while (b_idx < b_length) {
        merged_array[m_idx++] = array_b[b_idx++];
    }
    while (a_idx < a_length) {
        merged_array[m_idx++] = array_a[a_idx++];
    }

    return merged_array;
}

// TODO: size_t partition(size_t start, size_t end, size_t pivot_index)
// TODO: void quicksort(int *array, size_t start, size_t end)
