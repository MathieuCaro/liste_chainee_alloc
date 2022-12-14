#ifndef ALLOC_LIST_CHAINEE
#define ALLOC_LIST_CHAINEE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
    struct linked_list *previous;

} linked_list;

linked_list *new_element(int index);
void list_free(linked_list *list);
linked_list *add_index(linked_list *head, int data, int index);

#endif