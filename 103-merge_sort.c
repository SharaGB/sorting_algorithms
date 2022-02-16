#include "sort.h"
/**
 * mergeSort - Function to sort the subsection array.
 * @low: Is starting index.
 * @high: The last index of array.
 * @array: The array to sort.
 * @aux: The aux of the array.
 */
void mergeSort(int low, int high, int *array, int *aux)
{
	int mid = 0;

	if (high - low < 2) /* Si la subsección está vacía o es un solo elemento */
		return;

	mid = (low + high) / 2; /* Dividir el array a la mitad */
	/* y ordenar de forma independiente utilizando el mergeSort */
	mergeSort(low, mid, array, aux);  /* Ordenar las matrices */
	mergeSort(mid, high, array, aux); /* recursivamente */
	merge(low, mid, high, array, aux);

	for (mid = low; mid < high; mid++)
	{
		aux[mid] = array[mid]; /* Copia los elementos de array[] a aux[] */
	}
}

/**
 * merge - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @low: Is starting index.
 * @mid: The mid index.
 * @high: The last index of array.
 * @array: The array to sort.
 * @aux: The aux of the array.
 */
void merge(int low, int mid, int high, int *aux, int *array)
{
	int left = 0;
	int right = 0;
	int k = 0; /* Contador del loop */

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low);
	printf("[right]: ");
	print_array(array + mid, high - mid);
	printf("[Done]: ");
	print_array(aux + low, high - low);

	left = low;	 /* Apunta al comienzo del sub-array izquierdo */
	right = mid; /* Apunta al comienzo del sub-array derecho */

	/* Bucle de low a high para llenar cada elemento del array */
	for (k = low; k < high; k++)
	{
		/* if (left == mid + 1) Array izquierdo ha llegado a la última posición */
			/* aux[k] = array[left]; */
			/* left++; */
		/* else if (right == high + 1) Array derecho llega a la última posición */
			/* aux[k] = array[left]; */
			/* left++; */
		if (left < mid && (right >= high || array[left] <= array[right]))
		{
			aux[k] = array[left];
			left++;
		}
		else /* Array derecho apunta al elemento más pequeño */
		{
			aux[k] = array[right];
			right++;
		}
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: Always 0.
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *ptr = NULL;

	if (array == NULL || size < 2)
		return;
	ptr = malloc(sizeof(int) * size);
	if (ptr == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		ptr[i] = array[i];
	}
	mergeSort(0, size, array, ptr);
	free(ptr);
}
