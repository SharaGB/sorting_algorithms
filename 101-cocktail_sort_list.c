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
	listint_t *tmp = *list;

	while (swap == 0)
		swap = 0;
	while (swap != 0)
	{
		swap = 0;
		while (tmp->prev != NULL)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_cocktail(list, tmp->prev);
				swap = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
		if (swap == 0)
		{
			break;
		}
		swap = 0;
		while (tmp->next != NULL)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_cocktail(list, tmp);
				swap = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
	}
}
