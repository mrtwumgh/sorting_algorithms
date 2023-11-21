#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: doubly linked list
 *
 * Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *nextnode = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (current = (*list)->next; current != NULL; current = nextnode)
	{
		nextnode = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = current->prev;
			}
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev == NULL)
			{
				*list = current;
			}
			else
			{
				current->prev->next = current;
			}
			print_list((const listint_t *)*list);
		}
	}
}
