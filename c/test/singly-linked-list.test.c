#include <stdio.h>

#include "../linked-list.h"

int main() {
    singly_linked_list *list_a = new_singly_linked_list();

    list_a->head = new_singly_linked_node();
    list_a->head->data = 10;

    list_a->head->next = new_singly_linked_node();
    list_a->head->next->data = 20;

    list_a->head->next->next = new_singly_linked_node();
    list_a->head->next->next->data = 30;

    singly_linked_node *end = list_end(list_a);

    printf("End: %d\n", end->data);
    print_singly_linked_list(list_a);

    for (int i = 10; i < 10; ++i) {
        append(list_a, i);
    }

    print_singly_linked_list(list_a);

    return 0;
}
