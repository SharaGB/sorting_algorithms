#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int swap = 0; /* Variable para indicar intercambios */

	if (array == NULL)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1]) /* Comparar elementos, orden ascendente(>) */
			{
				/* Intercambio de elementos */
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
