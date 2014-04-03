#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "linked-list.h"

singly_linked_node* new_singly_linked_node() {
    singly_linked_node *new_node = malloc(sizeof(singly_linked_node));
    assert(new_node);

    new_node->next = NULL;
    return new_node;
}

singly_linked_list* new_singly_linked_list() {
    singly_linked_list *new_list = malloc(sizeof(singly_linked_list));
    assert(new_list);

    new_list->head = NULL;
    return new_list;
}

void free_list(singly_linked_list *list) {
}

bool is_empty(singly_linked_list *list) {
    if (list->head == NULL)
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
        singly_linked_node *iterator = list->head;
        for (length = 1; iterator->next != NULL; ++length, iterator = iterator->next) {}
        return length;
    }
}

void print_singly_linked_list(singly_linked_list *list) {
    if (is_empty(list)) {
        printf("[]");
    }
    else  {
        singly_linked_node *iterator = list->head;
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

void push(singly_linked_list *list, int data) {
    singly_linked_node *new_node = new_singly_linked_node();
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

int pop(singly_linked_list *list) {
    if (is_empty(list)) {
        fprintf(stderr, "[ERROR]: Pop from empty list\n");
        exit(1);
    }
    else {
        singly_linked_node *temp = list->head;
        int value = temp->data;

        list->head = temp->next;
        free(temp);

        return value;
    }
}

void append(singly_linked_list *list, int data) {
    singly_linked_node *appendee, *end;

    appendee = new_singly_linked_node();
    appendee->data = data;

    end = list_end(list);
    end->next = appendee;
}

void insert(singly_linked_list *list, int index, int data) {
    singly_linked_node *new_node = new_singly_linked_node();
    new_node->data = data;

    if (is_empty(list))  {
        if (index == 0) {
            list->head = new_node;
        }
        else {
            fprintf(stderr, "[ERROR]: List is empty. Invalid index.\n");
            exit(1);
        }
    }
    else {
        singly_linked_node *iterator;
        int i = 0;

        for (iterator = list->head;
             iterator->next != NULL && i < index - 1;
             iterator = iterator->next, ++i) {}

        if (i < index - 1) {
            fprintf(stderr, "[ERROR]: Index out of range.\n");
            exit(1);
        }

        new_node->next = iterator->next;
        iterator->next = new_node;
    }
}

/* TODO: */
/* void delete(singly_linked_list *list, int index) {} */
/* void reverse(singly_linked_list *list) {} */
/* void sort(singly_linked_list *list, int (*cmp)(int a, int b)) {} */
