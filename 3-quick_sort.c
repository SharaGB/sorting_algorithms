#include "sort.h"
/**
 * swap - Function that exchanges elements.
 * @array: The array to sort.
 * @i: The index to array.
 * @j: The index to array.
 *
 * Return: Always 0.
 */
void swap(int *array, size_t i, size_t j)
{
	int swap = 0;

	swap = array[i];
	array[i] = array[j];
	array[j] = swap;
}

/**
 * partition - Function
 * @array: The array to sort.
 * @low: Is starting index.
 * @high: The last index of array.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
int partition(int *array, int low, int high, size_t size)
{
	int j = 0;
	int i = 0;
	int pivot = 0;

	i = (low - 1); /* Índice del elemento más pequeño */
	pivot = array[high]; /* Elemento en la posición más alta */

	for (j = low; j <= high - 1; j++)
	{
		/* Si el elemento actual es menor que pivot, intercambian elementos */
		if (array[j] < pivot)
		{
			i++; /* Incremento el índice del elemento más pequeño */
			if (i != j)
			{
				swap(array, i, j); /* Llamo a mi función para intercambiar elementos */
				print_array(array, size);
			}
		}
	}
	swap(array, i + 1, high);
	print_array(array, size);
	return (i + 1);
}

/**
 * quickSort - Sorts an array of integers in ascending order.
 * @array: The array to sort.
 * @low: Is starting index.
 * @high: The last index of array.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = partition(array, low, high, size); /* Índice de partición */

		quickSort(array, low, pivot - 1, size); /* Antes de pivot */
		quickSort(array, pivot + 1, high, size); /* Después */
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL) /* Comprueba si no hay elementos */
	{
		return;
	}
	quickSort(array, 0, size - 1, size);
}
