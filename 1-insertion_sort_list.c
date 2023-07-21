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
 * insertion_sort_list - sorts a linked list of integers in ascending order.
 * @list: a double pointer to a doubly linked list.
 *
 * Discreption: this function uses Insertion sort algorithm.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *prevList;
	int val;


	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}

	tmp = *list;
	while (tmp)
	{
		prevList = tmp->prev;
		val = tmp->n;

		while (prevList && prevList->n > val)
		{
			swapList(prevList, tmp, list);
			print_list(*list);
			prevList = tmp->prev;
		}
		tmp = tmp->next;
	}
}
