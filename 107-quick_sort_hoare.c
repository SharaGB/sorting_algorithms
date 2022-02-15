#include "sort.h"
/**
 * swap_hoare - Function that exchanges elements.
 * @array: The array to sort.
 * @i: The index to array.
 * @j: The index to array.
 *
 * Return: Always 0.
 */
void swap_hoare(int *array, int i, int j)
{
	int swap = 0;

	swap = array[i];
	array[i] = array[j];
	array[j] = swap;
}

/**
 * partition_hoare - Function that orders elements (Lomuto).
 * @array: The array to sort.
 * @low: Is starting index.
 * @high: The last index of array.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
int partition_hoare(int *array, int low, int high, size_t size)
{
	int pivot = 0;

	pivot = array[high]; /* Elemento en la posición más alta */

	while (low <= high)
	{
		while (array[high] > pivot)
			high--;

		while (array[low] < pivot)
			low++;

		if (low <= high)
		{
			if (low != high)
			{
				swap_hoare(array, low, high);
				print_array(array, size);
			}
			low++;
			high--;
		}
		else
			return (high);
	}
	return (high);
}

/**
 * quickSort_hoare - Sorts an array of integers in ascending order.
 * @array: The array to sort.
 * @low: Is starting index.
 * @high: The last index of array.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
void quickSort_hoare(int *array, int low, int high, size_t size)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = partition_hoare(array, low, high, size); /* Índice de partición */

		quickSort_hoare(array, low, pivot, size);	   /* Antes de pivot */
		quickSort_hoare(array, pivot + 1, high, size); /* Después */
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL) /* Comprueba si no hay elementos */
	{
		return;
	}
	quickSort_hoare(array, 0, size - 1, size);
}
