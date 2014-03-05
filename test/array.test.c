#include "../arrays/array.h"

int main() {
    
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {10, 1234, 20, 4321, 30};
    int c[] = {11, 12, 13, 14, 15};
    int d[] = {8, 7, 6, 5, 4, 3};
    int e[] = {};

    printf("Left rotation:\n");

    print_array(a, 5);
    left_rotate_array(a, 5);
    print_array(a, 5);

    printf("Subarray rotation:\n");

    print_array(b, 5);
    left_rotate_subarray(b, 5, 1, 3);
    print_array(b, 5);

    printf("Fully rotating an array:\n");

    print_array(c, 5);

    for (int i = 0; i < 5; ++i) {
        left_rotate_array(c, 5);
        print_array(c, 5);
    }

    printf("Reversing an array:\n");
    print_array(a, 5);
    reverse_array(a, 5);
    print_array(a, 5);

    print_array(d, 5);
    reverse_array(d, 5);
    print_array(d, 5);

    printf("Recursive procedure to print array:\n");
    print_array_rec(d, 5);
    print_array_rec(e, 0);

    return 0;
}
