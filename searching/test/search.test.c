#include <stdio.h>
#include "../search.h"

int main() {

    int a[] = {34, 65, 745, -70, 435, 78, 12, -4, 5, 123};
    int e[] = {};

    int search[] = {-70, 42};

    print_array(a, 10);
    printf("Searching for element: %d\n", search[0]);
    printf("-70 is at: a[%d]\n", linear_search(a, 10, search[0]));

    printf("Searching for element: %d\n", search[1]);
    if (linear_search(a, 10, search[1]) < 0) {
        printf("Element %d is not in the array.\n", search[1]);
    }

    printf("Searching for element in empty array: %d\n", search[1]);
    if (linear_search(e, 0, search[1]) < 0) {
        printf("Element %d is not in the array.\n", search[1]);
    }

    printf("Recursively:\n");

    printf("Searching for element: %d\n", search[0]);
    printf("-70 is at: a[%d]\n", linear_search_rec(a, 10, search[0]));

    printf("Searching for element: %d\n", search[1]);
    if (linear_search_rec(a, 10, search[1])) {
        printf("Element %d is not in the array.\n", search[1]);
    }

    printf("Searching for element in empty array: %d\n", search[1]);
    if (linear_search_rec(e, 0, search[1]) < 0) {
        printf("Element %d is not in the array.\n", search[1]);
    }

    printf("Binary search:\n");

    int sorted_array[] = {3, 4, 5, 7, 8, 9, 10, 20, 40, 42};

    printf("Searching for element: %d\n", 8);
    printf("8 is at: a[%d]\n", binary_search(sorted_array, 8, 0, 9));

    printf("Searching for element: %d\n", 6);
    if (binary_search(sorted_array, 6, 0, 9)) {
        printf("Element %d is not in the array.\n", 6);
    }

    return 0;
}
