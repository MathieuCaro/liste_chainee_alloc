
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "linked_list.h"

linked_list *new_element(int index, void *ptr)
{

    linked_list *element = (linked_list *)malloc((sizeof(linked_list)));
    if (element == NULL)
    {
        printf("Probleme d'allocation memoire");
        exit(1);
    }
    element->next = NULL;
    element->previous = NULL;
    element->size = index;
    element->ptr = ptr;
    return element;
}
void list_free(linked_list *list)
{
    linked_list *tmp;
    linked_list *first = list;
    while (first)
    {
        tmp = first;
        first = first->next;
        free(tmp);
    }
    if (list != NULL)
    {
        list = NULL;
    }
}

linked_list *add_index(linked_list *head, int data, int index, void *ptr)
{
    linked_list *added_index = head, *temp;
    int compteur = 0;
    while (compteur < index - 1)
    {
        added_index = added_index->next;
        compteur++;
    }

    temp = new_element(data, ptr);
    temp->next = added_index;
    if (added_index == NULL)
    {
        temp->previous = NULL;
        return temp;
    }
    temp->previous = added_index->previous;
    if (added_index->previous)
    {
        added_index->previous->next = temp;
    }
    added_index->previous = temp;
    if (index == 0)
    {
        return temp;
    }
    return head;
}

void pop(linked_list *head)
{
    linked_list *last_one = head;
    while (last_one->next != NULL)
    {
        last_one = last_one->next;
    }
    last_one->previous->next = NULL;
    free(last_one);
}

linked_list *list_search(linked_list *head, int data)
{
    linked_list *list_search = head;
    while (list_search)
    {
        if (list_search->size >= data)
            return list_search;
        list_search = list_search->next;
    }
    return NULL;
}

linked_list *list_remove(linked_list *head, linked_list *to_be_deleted)
{
    linked_list *_new_head = NULL;
    if (to_be_deleted->previous)
    {
        to_be_deleted->previous->next = to_be_deleted->next;
        _new_head = head;
    }
    if (to_be_deleted->next)
    {
        to_be_deleted->next->previous = to_be_deleted->previous;
        if (_new_head == NULL)
        {
            _new_head = to_be_deleted->next;
        }
    }
    free(to_be_deleted);
    return _new_head;
}

void add_before(linked_list *head, void *ptr, int size)
{
    linked_list *add_before = head, *temp;
    if (add_before == NULL)
    {
        return;
    }
    while (((char *)ptr - (char *)add_before->ptr) && (add_before->next))
    {
        add_before = add_before->next;
    }

    temp = new_element(size, ptr);
    temp->next = add_before;
    temp->previous = add_before->previous;
    if (temp->previous)
    {
        add_before->previous->next = temp;
    }
    add_before->previous = temp;
}