#include "../sorting/sort.h"
#include "../arrays/array.h"

int main() {
    int a[] = {5, -6, 67, -3, 0, 78, 123, -8, 42, -1};
    int b[] = {123, -5, 0, 4, 67, -87, -2, 89, -12, -2};
    int c[] = {1, 2, 3, 4, -1000};

    int a1[] = {3, 4, 5, 6, 7};
    int a2[] = {-7, -5, -4, -2, 0, 2};

    int b1[] = {1, 2, 3, 4};
    int b2[] = {-4, -3, -2, -1};

    print_array(b1, 4);
    printf("merged with: \n");
    print_array(b2, 4);
    printf("gives: \n");
    int *m2 = merge_arrays(b1, 4, b2, 4);
    print_array(m2, 8);

    print_array(a1, 5);
    printf("merged with: \n");
    print_array(a2, 6);
    int *m1 = merge_arrays(a1, 5, a2, 6);
    printf("gives: \n");
    print_array(m1, 11);

    printf("Insertion sort:\n");

    assert(is_sorted(c, 5) == 0);

    print_array(a, 10);
    insertion_sort(a, 10);
    print_array(a, 10);

    assert(is_sorted(a, 10) );

    print_array(b, 10);
    insertion_sort(b, 10);
    print_array(b, 10);

    assert(is_sorted(b, 10) == 1);

    int d[] = {5, -6, 67, -3, 0, 78, 123, -8, 42, -1};
    int e[] = {123, -5, 0, 4, 69, -87, -2, 89, -12, -2};
    int f[] = {1, 2, 3, 4, -1000};

    printf("Selection sort:\n");

    print_array(d, 10);
    selection_sort(d, 10);
    assert(is_sorted(d, 10));
    print_array(d, 10);

    print_array(e, 10);
    selection_sort(e, 10);
    assert(is_sorted(e, 10));
    print_array(e, 10);

    print_array(f, 5);
    selection_sort(f, 5);
    assert(is_sorted(f, 5));
    print_array(f, 5);

    int g[] = {5, -6, 67, -3, 0, 78, 123, -8, 42, -1};
    int h[] = {123, -5, 0, 4, 69, -87, -2, 89, -12, -2};
    int i[] = {1, 2, 3, 4, -1000};

    printf("Bubble sort:\n");

    print_array(g, 10);
    bubble_sort(g, 10);
    assert(is_sorted(g, 10));
    print_array(g, 10);

    print_array(h, 10);
    bubble_sort(h, 10);
    assert(is_sorted(h, 10));
    print_array(h, 10);

    print_array(i, 5);
    bubble_sort(i, 5);
    assert(is_sorted(i, 5));
    print_array(i, 5);

    return 0;
}
