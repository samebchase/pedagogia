#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "linked-list.h"

singly_linked_list* new_singly_linked_list() {
    singly_linked_list *list = malloc(sizeof(singly_linked_list));
    assert(list);

    list->head = NULL;
    return list;
}

singly_linked_node* new_singly_linked_node() {
    singly_linked_node *new_node = malloc(sizeof(singly_linked_node));
    assert(new_node);

    new_node->next = NULL;
    return new_node;
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

char* string(singly_linked_list *list) {
    const size_t list_size = list_length(list);
    const size_t comma_spaces = list_size - 1;
    size_t total_number_chars = 0;
    char *number_strings[list_size];
    singly_linked_node *iterator = list->head;

    for (size_t i = 0;
         i < list_size && iterator->next != NULL;
         iterator = iterator->next, ++i) {
        
        total_number_chars += sprintf(number_strings[i], "%d", iterator->data);
     }

    const size_t result_string_size = total_number_chars + 2 * comma_spaces + 3;
    char* result_string = malloc(sizeof(char) * result_string_size);
    assert(result_string);

    // Copy characters
    result_string[0] = '[';

    iterator = list->head;
    for (size_t i = 0, k = 1;
         i < list_size && iterator->next != NULL && k < result_string_size;
         ++i, iterator = iterator->next) {

        for (size_t j = 0; j < strlen(number_strings[i]); ++j) {
            result_string[k] = number_strings[i][j];
            ++k;
        }

        if (i < list_size - 2) {
            result_string[k] = ',';
            ++k;
            result_string[k] = ' ';
            ++k;
        }
    }

    result_string[result_string_size - 2] = ']';
    result_string[result_string_size - 1] = '\0';

    return result_string;
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

void delete(singly_linked_list *list, int index) {}

void slice(singly_linked_list *list, int start_index, int end_index) {}

void reverse(singly_linked_list *list) {}

void sort(singly_linked_list *list, int (*cmp)(int a, int b)) {}
