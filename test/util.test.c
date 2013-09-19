#include "../util.h"
#include "../array.h"

int main() {

    int array[] = {1234, 4321};
    printf("Swapping:\n");
    print_array(array, 2);
    swap(&array[0], &array[1]);
    print_array(array, 2);

    printf("Array generation:\n");
    int *foo = generate_array(16);
    print_array(foo, 16);
    randomise_array(foo, 16, -100, 100);
    print_array(foo, 16);

    return 0;
}
