#include "sort.h"
/**
 * swap_nodes - swapes two nodes in a linked list.
 * @a: first node.
 * @b: second node.
 * @list: the list to be sorted.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *tmp;

	tmp = a->prev;
	if (tmp)
		tmp->next = b;
	if (b->next)
		b->next->prev = a;
	if (tmp == NULL)
		*list = b;
	a->next = b->next;
	b->next = a;
	a->prev = b;
	b->prev = tmp;
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
	while (swapped != 0)
	{
		swapped = 0;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
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
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		start = current;
	}
}
