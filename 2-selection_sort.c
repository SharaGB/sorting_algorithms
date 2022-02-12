#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	size_t position = 0;
	int swap = 0;

	if (array == NULL)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		position = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[position] > array[j]) /* Para ordenar en orden ascendente(>) */
			{
				position = j;
			}
		}
		if (position != i)
		{
			/* Intercambiar el elemento mínimo encontrado con el primer elemento */
			swap = array[i];
			array[i] = array[position];
			array[position] = swap;
			print_array(array, size);
		}
	}
}
