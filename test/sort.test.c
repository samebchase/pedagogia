#include "../sort.h"
#include "../array.h"

int main() {
    int a[] = {5, -6, 67, -3, 0, 78, 123, -8, 42, -1};
    int b[] = {123, -5, 0, 4, 67, -87, -2, 89, -12, -2};
    int c[] = {1, 2, 3, 4, -1000};

    assert(is_sorted(c, 5) == 0);

    print_array(a, 10);
    insertion_sort(a, 10);
    print_array(a, 10);

    assert(is_sorted(a, 10) == 1);

    print_array(b, 10);
    insertion_sort(b, 10);
    print_array(b, 10);

    assert(is_sorted(b, 10) == 1);

    return 0;
}
