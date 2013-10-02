#pragma once

typedef struct _singly_linked_node {
    int data;
    struct _singly_linked_node *next;
} singly_linked_node;

typedef struct _singly_linked_list {
    singly_linked_node *head;
} singly_linked_list;

singly_linked_node* new_singly_linked_node();

singly_linked_list* new_singly_linked_list();

singly_linked_node* list_end(singly_linked_list*);

void append(singly_linked_list*, int);

void print_singly_linked_list(singly_linked_list *);
