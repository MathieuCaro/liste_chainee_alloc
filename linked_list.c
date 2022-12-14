
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "linked_list.h"

linked_list *new_element(int index)
{
    linked_list *element = (linked_list *)malloc((sizeof(linked_list)));
    if (element == NULL)
    {
        printf("Probleme d'allocation memoire");
        exit(1);
    }
    element->next = NULL;
    element->previous = NULL;
    element->data = index;
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

linked_list *add_index(linked_list *head, int data, int index)
{
    linked_list *added_index = head, *temp;
    int compteur = 0;
    while (compteur < index - 1)
    {
        added_index = added_index->next;
        compteur++;
    }

    temp = new_element(data);
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