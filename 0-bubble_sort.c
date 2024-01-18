#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - Bubble sort implementation
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int ifSwap = 1;
	size_t i;
	int temp;

	while (ifSwap)
	{
		ifSwap = 0;
		for (i = 0; (i + 1) < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				ifSwap = 1;
				break;
			}
		}
		print_array(array, size);
	}
}
