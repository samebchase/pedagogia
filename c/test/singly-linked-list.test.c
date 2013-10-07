#include <stdio.h>

#include "../linked-list.h"

int main() {
    singly_linked_list *list_a = new_singly_linked_list();

    printf("Is empty?: %d\n", is_empty(list_a));

    printf("Length: %zu\n", list_length(list_a));
    printf("Empty list: ");
    print_singly_linked_list(list_a);
    printf("\n");

    for (int i = 1; i <= 10; ++i) {
        push(list_a, i * 10);
        printf("Length: %zu\n", list_length(list_a));
        print_singly_linked_list(list_a);
        printf("\n");
    }

    singly_linked_node *end = list_end(list_a);
    printf("End: %d\n", end->data);

    for (int i = 0; i < 5; ++i) {
        append(list_a, i * 5);
    }

    printf("Length: %zu\n", list_length(list_a));
    printf("End: %d\n", list_end(list_a)->data);

    print_singly_linked_list(list_a);
    printf("\n");

    for (int i = 0; i < 5; ++i) {
        printf("Pop: %d\n", pop(list_a));
    }

    print_singly_linked_list(list_a);
    printf("\n");

    singly_linked_list *empty = new_singly_linked_list();

    pop(empty);

    return 0;
}
