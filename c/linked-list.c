#include <stdlib.h>
#include <stdio.h>

#include "linked-list.h"

singly_linked_list* new_singly_linked_list() {
    singly_linked_list *list = malloc(sizeof(singly_linked_list));
    list->head = NULL;
    return list;
}

void free_list(singly_linked_list *list) {
}

singly_linked_node* new_singly_linked_node() {
    singly_linked_node *new_node = malloc(sizeof(singly_linked_node));
    new_node->next = NULL;
    return new_node;
}

void print_singly_linked_list(singly_linked_list *list) {
    singly_linked_node *iterator;
    iterator = list->head;
    printf("[");
    do {
        printf("%d, ", iterator->data);
        iterator = iterator->next;
    }
    while (iterator->next != NULL);
    printf("%d", iterator->data);
    printf("]\n");
}

singly_linked_node* list_end(singly_linked_list *list) {
    singly_linked_node *iterator, *end;
    for (iterator = list->head; iterator->next != NULL; iterator = iterator->next) {}
    end = iterator;
    return end;
}

void append(singly_linked_list *list, int data) {
    singly_linked_node *appendee, *end;

    appendee = new_singly_linked_node();
    appendee->data = data;

    end = list_end(list);
    end->next = appendee;
}
