#include "sort.h"
/**
 * swap - swaps
 *
 * @a: int
 * @b: int
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * sift_down - sifts down
 *
 * @array: arr
 * @root: root
 * @end: end
 * Return: void
 */
void sift_down(int *array, int root, int end)
{
	int child, temp;

	temp = array[root];
	while ((2 * root) + 1 <= end)
	{
		child = 2 * root + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
		{
			child++;
		}
		if (temp < array[child])
		{
			array[root] = array[child];
			root = child;
		}
		else
		{
			break;
		}
	}
	array[root] = temp;
}
/**
 * heap_sort - heap sort
 *
 * @array: arr
 * @size: size
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		sift_down(array, i, size - 1);
	}
	for (i = size - 1; i >= 1; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, 0, i - 1);
	}
}
