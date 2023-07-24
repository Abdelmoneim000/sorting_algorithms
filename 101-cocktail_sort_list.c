#include "sort.h"
/**
 * swapList - swaps two nodes in a linked list.
 * @a: a pointer to a linked list.
 * @b: a pointer to a linked list.
 * @head: a double pointer to a linked list.
 */
void swapList(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *list1 = NULL, *list2 = NULL;

	if (a == NULL || b == NULL)
		return;
	list1 = a->prev;
	list2 = b->next;

	if (list1)
		list1->next = b;
	if (list2)
		list2->prev = a;
	a->next = list2;
	a->prev = b;
	b->next = a;
	b->prev = list1;
	if (list1 == NULL)
		*head = b;
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
	listint_t *last_swap = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (end != start)
	{
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swapList(current, current->next, list);
				print_list(*list);
				last_swap = current->next;
			}
			current = current->next;
		}

		end = last_swap;
		current = last_swap->prev;

		while (current != start)
		{
			if (current->n > current->next->n)
			{
				swapList(current, current->next, list);
				print_list(*list);
				last_swap = current->next;
			}
			current = current->prev;
		}

		start = last_swap;
		current = last_swap;
	}
}
