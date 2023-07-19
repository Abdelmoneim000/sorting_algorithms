#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order using the insertion sort algorithm
 *
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev_node, *next_node;
    
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;


    current = (*list)->next;
    while (current != NULL)
    {
        prev_node = current->prev;
        next_node = current->next;

        while (prev_node != NULL && prev_node->n > current->n)
        {
            prev_node->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev_node;

            current->prev = prev_node->prev;
            current->next = prev_node;
            if (prev_node->prev != NULL)
                prev_node->prev->next = current;
            prev_node->prev = current;

            prev_node = current->prev;
            if (prev_node == NULL)
                *list = current;
        }

        current = next_node;
    }

    current = *list;
    while (current->next != NULL)
        current = current->next;
    current->next = NULL;
}