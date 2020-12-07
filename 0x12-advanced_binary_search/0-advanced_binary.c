#include "search_algos.h"

/**
* print_array - print array
*
* @array: the sorted array.
* @start: the start of array.
* @end: the end of array.
* Return: nothing
*/
void print_array(int *array, int start, int end)
{
	printf("Searching in array: ");
	while (start < end)
	{
		printf("%d, ", array[start]);
		start++;
	}
	printf("%d\n", array[start]);
}

/**
* recursiveBinarySearch - searches for a value
* in a sorted array of integers.
*
* @array: the sorted array.
* @start: the start of array.
* @end: the end of array.
* @value: the value to find.
* Return: the value or -1 if fail.
*/

int recursiveBinarySearch(int *array, int start, int end, int value)
{
	int middle = 0;

	if (start > end)
		return (-1);

	print_array(array, start, end);

	middle = (start + end) / 2;

	if (array[middle] == value && (middle == start))
		return (middle);

	if (array[middle] >= value)
		return (recursiveBinarySearch(array, start, middle, value));

	return (recursiveBinarySearch(array, middle + 1, end, value));

}

/**
* advanced_binary - searches for a value
* in a sorted array of integers.
*
* @array: the sorted array.
* @size: the size of array.
* @value: the value to find.
* Return: the value or -1 if fail.
*/

int advanced_binary(int *array, size_t size, int value)
{
	int result;

	if (!array)
		return (-1);
	result = recursiveBinarySearch(array, 0, size - 1, value);

	return (result);
}
