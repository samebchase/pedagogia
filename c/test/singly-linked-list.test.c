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
    singly_linked_list *sorted_list = new_singly_linked_list();

    for (int i = 20; i > 10; --i) {
        push(sorted_list, i);
    }

    printf("Sorted list: ");
    print_singly_linked_list(sorted_list);
    printf("\n");

    printf("Insert 1984 at list[3]: ");
    insert(sorted_list, 3, 1984);
    print_singly_linked_list(sorted_list);
    printf("\n");

    printf("Insert 2199 at list[0]: ");
    insert(sorted_list, 0, 2199);
    print_singly_linked_list(sorted_list);
    printf("\n");

    printf("Insert 9999 at list[12]: ");
    insert(sorted_list, 12, 9999);
    print_singly_linked_list(sorted_list);
    printf("\n");

    printf("Insert into empty list: ");
    insert(empty, 0, 12345);
    print_singly_linked_list(empty);
    printf("\n");

    return 0;
}
