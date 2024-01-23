#include "sort.h"
#include <stdio.h>

/**
 * lpartition - Lomuto partition implementation
 * @array: Array to be sorted
 * @size: Size of the array
 * @low: Contains the lowest index of the array
 * @high: Contains the highest index of the array
 *
 * Return: Pivot position
*/

int lpartition(int *array, size_t size, int low, int high)
{
	int i = low - 1, j;
	int pivot = array[high], temp;

	for (j = low; j < high; j++)
	{
		if (pivot >= array[j])
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if ((i + 1) != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * QuickSort - Inner implementation of the quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * @low: Contains the lowest index of the array
 * @high: Contains the highest index of the array
 *
 * Return: nothing
*/

void QuickSort(int *array, size_t size, int low, int high)
{
	int parti;

	if (low < high)
	{
		parti = lpartition(array, size, low, high);
		QuickSort(array, size, low, parti - 1);
		QuickSort(array, size, parti + 1, high);
	}
}

/**
 *  quick_sort - Implementation of the quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array to be sorted
 *
 * Return: nothing
*/

void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	QuickSort(array, size, low, high);
}
