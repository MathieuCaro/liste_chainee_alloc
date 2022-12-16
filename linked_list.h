#ifndef ALLOC_LIST_CHAINEE
#define ALLOC_LIST_CHAINEE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct linked_list
{
    void *ptr;
    int size;
    struct linked_list *next;
    struct linked_list *previous;

} linked_list;

linked_list *new_element(int index, void *ptr);
void list_free(linked_list *list);
linked_list *add_index(linked_list *head, int data, int index, void *ptr);
linked_list *list_search(linked_list *head, int data);
void pop(linked_list *head);
linked_list *list_remove(linked_list *head, linked_list *to_be_deleted);
void add_before(linked_list *head, void *ptr, int size);

#endif