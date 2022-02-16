#ifndef _SORT_H_
#define _SORT_H_
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size); /* Inccompleto */
void heap_sort(int *array, size_t size); /* Inccompleto */
void radix_sort(int *array, size_t size); /* Inccompleto */
void bitonic_sort(int *array, size_t size); /* Inccompleto */
void quick_sort_hoare(int *array, size_t size);

/* For Quick sort algorithm */
void swap(int *array, int i, int j);
int partition(int *array, int low, int high, size_t size);
void quickSort(int *array, int low, int high, size_t size);

/* For Cocktail shaker sort algorithm */
void swap_cocktail(listint_t **list, listint_t *n);

/* For Merge sort algorithm */
void mergeSort(int low, int high, int *array, int *aux);
void merge(int low, int mid, int high, int *aux, int *array);

/* For Randix sort */

/* For Quick sort Hoare */
void swap_hoare(int *array, int i, int j);
int partition_hoare(int *array, int low, int high, size_t size);
void quickSort_hoare(int *array, int low, int high, size_t size);

#endif /* _SORT_H_ */
