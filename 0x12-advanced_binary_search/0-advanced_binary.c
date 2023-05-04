#include "search_algos.h"
/**
 * advanced_binary_recursive - uses low and high for binary search
 *
 * @array: arr
 * @low: low
 * @high: high
 * @value: value
 *
 * Return: value
 */
int advanced_binary_recursive(int *array, int low, int high, int value)
{
	int mid, i;

	if (low > high)
		return (-1);

	mid = (low + high) / 2;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
		printf("%d%s", array[i], i == high ? "\n" : ", ");

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		else
			return (advanced_binary_recursive(array, low, mid, value));
	}
	else if (array[mid] > value)
		return (advanced_binary_recursive(array, low, mid - 1, value));
	else
		return (advanced_binary_recursive(array, mid + 1, high, value));
}
/**
 * advanced_binary - binary search recursively
 *
 * @array: array
 * @size: size
 * @value: value
 *
 * Return: int
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
