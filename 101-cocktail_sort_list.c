#include "sort.h"
/**
 * swap_cocktail - Function that exchanges elements in doubly linked list.
 * @list: Head of the doubly linked list.
 * @n: The node.
 *
 * Return: Always 0.
 */
void swap_cocktail(listint_t **list, listint_t *n)
{
	if (list == NULL || *list == NULL)
	{
		return;
	}
	if (n->prev != NULL)
	{
		n->prev->next = n->next;
	}
	else
	{
		*list = n->next;
	}
	n->next->prev = n->prev;
	n->prev = n->next;
	n->next = n->next->next;
	n->prev->next = n;
	if (n->next != NULL)
	{
		n->next->prev = n;
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: Head of the doubly linked list.
 *
 * Return: Always 0.
 */
void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *ptr = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ptr = *list;
	while (swap != 0)
	{
		swap = 0;
		while (ptr->next != NULL)
		{
			if (ptr->n > ptr->next->n)
			{
				swap = 1;
				swap_cocktail(list, ptr);
				print_list(*list);
			}
			else
				ptr = ptr->next;
		}
		if (swap == 0)
		{
			break;
		}
		swap = 0;
		while (ptr->prev != NULL)
		{
			if (ptr->prev->n > ptr->n)
			{
				swap = 1;
				swap_cocktail(list, ptr->prev);
				print_list(*list);
			}
			else
				ptr = ptr->prev;
		}
	}
}
