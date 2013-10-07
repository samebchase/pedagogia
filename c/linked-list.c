#include <stdio.h>
#include <stdlib.h>

#include "linked-list.h"

singly_linked_list* new_singly_linked_list() {
    singly_linked_list *list = malloc(sizeof(singly_linked_list));
    list->head = new_singly_linked_node();
    return list;
}

void free_list(singly_linked_list *list) {
}

singly_linked_node* new_singly_linked_node() {
    singly_linked_node *new_node = malloc(sizeof(singly_linked_node));
    new_node->next = NULL;
    return new_node;
}

bool is_empty(singly_linked_list *list) {
    if (list->head->next == NULL)
        return true;
    else
        return false;
}

size_t list_length(singly_linked_list *list) {
    if (is_empty(list)) {
        return 0;
    }
    else {
        size_t length;
        singly_linked_node *iterator = list->head->next;
        for (length = 1; iterator->next != NULL; ++length, iterator = iterator->next) {}
        return length;
    }
}

void push(singly_linked_list *list, int data) {
    singly_linked_node *new_node = new_singly_linked_node();
    new_node->data = data;
    new_node->next = list->head->next;
    list->head->next = new_node;
}

void print_singly_linked_list(singly_linked_list *list) {
    if (is_empty(list)) {
        printf("[]");
    }
    else  {
        singly_linked_node *iterator = list->head->next;
        printf("[");

        while (iterator->next != NULL) {
            printf("%d, ", iterator->data);
            iterator = iterator->next;
        }

        printf("%d", iterator->data);
        printf("]");
    }
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
