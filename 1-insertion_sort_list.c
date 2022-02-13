#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Head of the list.
 *
 * Return: Always 0.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nxt = NULL;
	listint_t *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	else
	{
		nxt = (*list)->next;
		while (nxt != NULL)
		{
			tmp = nxt->next;
			while (nxt->prev != NULL && nxt->prev->n > nxt->n) /* Orden ascendente */
			{
				if (nxt->next != NULL)
				{
					nxt->next->prev = nxt->prev;
				}
				nxt->prev->next = nxt->next;
				nxt->next = nxt->prev;
				nxt->prev = nxt->next->prev;
				nxt->next->prev = nxt;
				if (nxt->prev != NULL)
				{
					nxt->prev->next = nxt;
				}
				else
				{
					*list = nxt;
				}
				print_list(*list);
			}
			nxt = tmp;
		}
	}
}
