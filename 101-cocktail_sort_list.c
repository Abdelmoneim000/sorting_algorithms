#include "sort.h"
/**
 * swap_nodes - swapes two nodes in a linked list.
 * @n1: first node.
 * @n2: second node.
 */
void swap_nodes(listint_t *n1, listint_t *n2)
{
	listint_t *temp_next, *temp_prev;

	if (!n1 || !n2 || n1 == n2)
		return;
	if (n1->next == n2)
	{
		n1->next = n2->next;
		n2->prev = n1->prev;
		n1->prev = n2;
		n2->next = n1;
		if (n1->next)
			n1->next->prev = n1;
		if (n2->prev)
			n2->prev->next = n2;
	}
	else
	{
		temp_next = n1->next;
		temp_prev = n1->prev;
		n1->next = n2->next;
		n1->prev = n2->prev;
		n2->next = temp_next;
		n2->prev = temp_prev;
		if (n1->next)
			n1->next->prev = n1;
		if (n1->prev)
			n1->prev->next = n1;
		if (n2->next)
			n2->next->prev = n2;
		if (n2->prev)
			n2->prev->next = n2;
	}
}
/**
 * cocktail_sort_list - sorts a daubly linked list of integers
 *			in ascending order.
 * @list: the list to be sorted.
 *
 * Description: this function uses the Cocktail shaker sort algorithm.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current = *list;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		end = current;
		if (!swapped)
			break;
		swapped = 0;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
		start = current;
	}
}
