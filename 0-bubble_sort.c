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
	/* Variable temporal para mantener */
	/* los valores mientras se intercambia */
	int tmp = 0;

	if (array == NULL)
	{
		return;
	}
	while (i < size)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1]) /* Comparar elementos, orden ascendente(>) */
			{
				/* Intercambio de elementos */
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}
