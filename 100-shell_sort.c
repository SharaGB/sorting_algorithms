#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i = 0;
	size_t j = 0;
	int tmp = 0;

	if (array == NULL)
	{
		return;
	}
	while (interval < size / 3)
	{
		interval = interval * 3 + 1; /* Secuencia de intervalos(Knuth) */
	}
	while (interval > 0)
	{
		/* Realiza una clasificación de inserción de intervalos */
		/* Sigue añadiendo elementos hasta que todo el array esté ordenado */
		for (i = interval; i < size; i += 1)
		{
			/* Añadir ar[i] a los elementos que han sido ordenados y guardalos en tmp*/
			tmp = array[i];
			/* Desplzamos los elementos ordenados hasta que encuentre ña unibación */
			/* correcta de array[i] */
			for (j = i; j >= interval && array[j - interval] > tmp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = tmp; /* Poner en el lugar correcto al elemetno tmp */
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
