#include "../sort.h"
#include "../array.h"

int main() {
    int a[] = {5, -6, 67, -3, 0, 78, 123, -8, 42, -1};
    int b[] = {123, -5, 0, 4, 67, -87, -2, 89, -12, -2};
    int c[] = {1, 2, 3, 4, -1000};

    printf("Insertion sort:\n");

    assert(is_sorted(c, 5) == 0);
    
    print_array(a, 10);
    insertion_sort(a, 10);
    print_array(a, 10);

    assert(is_sorted(a, 10) == 1);

    print_array(b, 10);
    insertion_sort(b, 10);
    print_array(b, 10);

    assert(is_sorted(b, 10) == 1);

    int d[] = {5, -6, 67, -3, 0, 78, 123, -8, 42, -1};
    int e[] = {123, -5, 0, 4, 67, -87, -2, 89, -12, -2};
    int f[] = {1, 2, 3, 4, -1000};

    printf("Selection sort:\n");

    print_array(d, 10);
    selection_sort(d, 10);
    print_array(d, 10);

    print_array(e, 10);
    selection_sort(e, 10);
    print_array(e, 10);

    print_array(f, 10);
    selection_sort(f, 10);
    print_array(f, 10);

    return 0;
}
