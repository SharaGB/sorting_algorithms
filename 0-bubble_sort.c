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
	int swap = 0;
	unsigned int tmp = 0; /* Variable para indicar intercambios */

	if (array == NULL)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1]) /* Comparar elementos, orden ascendente(>) */
			{
				/* Intercambio de elementos */
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				tmp = 1; /* Establecerlo a 1 para indicar que se ha hecho intercambios */
				print_array(array, size);
			}
		}
		if (tmp == 0) /* Si no hay intercambios se sale del bucle */
		{
			break;
		}
	}
}
