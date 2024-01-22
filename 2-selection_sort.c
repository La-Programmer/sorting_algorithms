#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Selection sort implementation
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: nothing
*/

void selection_sort(int *array, size_t size)
{
	size_t mov_ind = 0, i, smallest_ind = 0;
	int smallest;

	while (mov_ind < size - 1)
	{
		smallest = array[mov_ind];
		for (i = mov_ind; i < size; i++)
		{
			if (array[i] < smallest)
			{
				smallest = array[i];
				smallest_ind = i;
			}
		}
		printf("Smallest: %d\n", smallest);
		array[smallest_ind] = array[mov_ind];
		array[mov_ind] = smallest;
		print_array(array, size);
		mov_ind++;
	}
}
