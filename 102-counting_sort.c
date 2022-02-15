#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
void counting_sort(int *array, size_t size)
{
	size_t i = 0;
	int j = 0, swap = 0, num = 0, k_max = 0; /* Mayor número del array */
	int *count = NULL, *ptr = NULL;

	if (array == NULL || size < 2)
		return;
	ptr = malloc(sizeof(int) * size);
	if (ptr == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		ptr[i] = array[i];
		if (array[i] > k_max) /* Encuentra el elemento más grande del array */
			k_max = array[i];
	}
	count = malloc(sizeof(int) * (k_max + 1)); /* Hacemos malloc para count: */
	/* El tamaño de count debe ser (max+1) pero no podemos declararlo como */
	/* int count(max+1) ya que no soporta la asignación dinámica de memoria */
	if (count == NULL)
		return;

	for (j = 0; j <= k_max; j++)
		count[j] = 0; /* Inicializar array count */
	for (i = 0; i < size; i++)
		count[array[i]]++; /* Almacenar count de cada elemento */
	for (j = 0; j <= k_max; j++)
	{
		swap = count[j]; /* Sobreescribir count para mantenr el siguiente */
		count[j] = num; /* index de un elemento */
		num += swap;
	}
	for (i = 0; i < size; i++)
	{
		array[count[ptr[i]]] = ptr[i]; /* Colocar el elemento en el array ordenado */
		count[ptr[i]]++;
	}
	print_array(count, k_max + 1); /* Función para imprimir el array */
	free(ptr); /* Libero */
	free(count);
}
