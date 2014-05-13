#include "../sorting/sort.h"
#include "../arrays/array.h"

void test_array_sort(void (*sort_function)(int *array, size_t length), int *array, size_t length) {
    print_array(array, length);
    sort_function(array, length);
    assert(is_sorted(array, length));
    print_array(array, length);
}

int main() {
    int a[] = {5, -6, 67, -3, 0, 78, 123, -8, 42, -1};
    int b[] = {123, -5, 0, 4, 67, -87, -2, 89, -12, -2};

    int a1[] = {3, 4, 5, 6, 7};
    int a2[] = {-7, -5, -4, -2, 0, 2};

    int b1[] = {1, 2, 3, 4};
    int b2[] = {-4, -3, -2, -1};

    int c1[] = {6, 5, 3, 1, 21, 2, 9, 3, 4};
    int c2[] = {34, -2, 5, -5, -6, 0, -1};
    int c3[] = {-2, 2, -5, 4, -5, -8, 13, 3, 0, 3, -1};

    int l1[] = {6, 5, 3, 1, 21, 2, 9, 3, 4};
    int l2[] = {34, -2, 5, -5, -6, 0, -1};
    int l3[] = {-2, 2, -5, 4, -5, -8, 13, 3, 0, 3, -1};

    printf("Merging: \n");
    print_array(b1, 4);
    print_array(b2, 4);
    printf("gives: ");
    int *m2 = merge_arrays(b1, 4, b2, 4);
    print_array(m2, 8);

    printf("Merging: \n");
    print_array(a1, 5);
    print_array(a2, 6);
    printf("gives: \n");
    int *m1 = merge_arrays(a1, 5, a2, 6);
    print_array(m1, 11);
    printf("\n");

    int mer3[] = {2, 21};
    int mer4[] = {3, 4, 9};

    print_array(merge_arrays(mer3, 2, mer4, 3), 5);

    int mer5[] = {-6, -4, -1, 0, 13, 18};
    int mer6[] = {-4, -3, -2, -1, 3, 5};

    print_array(merge_arrays(mer5, 6, mer6, 6), 12);
    printf("\n");

    printf("Merge sort:\n");
    print_array(l1, 9);
    int *mr1 = merge_sort(l1, 9);
    print_array(mr1, 9);
    print_array(l2, 7);
    print_array(merge_sort(l2, 7), 7);
    print_array(l3, 11);
    print_array(merge_sort(l3, 11), 11);
    printf("\n");

    printf("Counting sort:\n");
    test_array_sort(counting_sort, c1, 9);
    test_array_sort(counting_sort, c2, 7);
    test_array_sort(counting_sort, c3, 11);
    printf("\n");

    printf("Insertion sort:\n");
    test_array_sort(insertion_sort, a, 10);
    test_array_sort(insertion_sort, b, 10);
    printf("\n");

    int d[] = {5, -6, 67, -3, 0, 78, 123, -8, 42, -1};
    int e[] = {123, -5, 0, 4, 69, -87, -2, 89, -12, -2};
    int f[] = {1, 2, 3, 4, -1000};

    printf("Selection sort:\n");
    test_array_sort(selection_sort, d, 10);
    test_array_sort(selection_sort, e, 10);
    test_array_sort(selection_sort, f, 5);
    printf("\n");

    int g[] = {5, -6, 67, -3, 0, 78, 123, -8, 42, -1};
    int h[] = {123, -5, 0, 4, 69, -87, -2, 89, -12, -2};
    int i[] = {1, 2, 3, 4, -1000};

    printf("Bubble sort:\n");
    test_array_sort(bubble_sort, g, 10);
    test_array_sort(bubble_sort, h, 10);
    test_array_sort(bubble_sort, i, 5);

    return 0;
}
