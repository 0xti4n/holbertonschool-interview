#include "slide_line.h"

/**
* right - slida an array in order to right.
* @line: Pointer to the array of integer to be printed
* @size: Number of elements in array
* Return: success.
*/

int right(int *line, size_t size)
{
	int new_size = 0, index, index_j, index_check, flag = 0;

	index_check = line[size - 1];
	new_size = (int)size;
	for (index = new_size - 1; index >= 0; index--)
	{
		for (index_j = index - 1; index_j >= 0; index_j--)
		{
			if (line[index_j] != 0)
			{
				if (index_check == line[index_j])
				{
					index_check += line[index_j];
					line[index_j] = 0;
					break;
				}
				else if (index_check == 0)
				{
					index_check = line[index_j];
					line[index] = index_check;
					line[index_j] = 0;
				}
				else
				{
					index_check = line[index];
					flag = 1;
					break;
				}
			}
		}
		line[index] = index_check;
		if (flag != 1)
			index_check = 0;
		else
		{
			index_check = line[index - 1];
			flag = 0;
		}
	}
	return (1);
}

/**
* left - slida an array in order to left.
* @line: Pointer to the array of integer to be printed
* @size: Number of elements in array
* Return: success.
*/

int left(int *line, size_t size)
{
	size_t i, j;
	int index_check = line[0], flag = 0;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (line[j] != 0)
			{
				if (index_check == line[j])
				{
					index_check += line[j];
					line[j] = 0;
					break;
				}
				else if (index_check == 0)
				{
					index_check = line[j];
					line[i] = index_check;
					line[j] = 0;
				}
				else
				{
					index_check = line[i];
					flag = 1;
					break;
				}
			}
		}
		line[i] = index_check;
		if (flag != 1)
			index_check = 0;
		else
		{
			index_check = line[i + 1];
			flag = 0;
		}
	}
	return (1);
}

/**
* slide_line - slida an array in order to left or right.
*
* @line: Pointer to the array of integer to be printed
* @size: Number of elements in array
* @direction: Direction to slide.
* Return: 1 if success 0 if not.
*/

int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		return (left(line, size));
	}
	if (direction == SLIDE_RIGHT)
	{
		return (right(line, size));
	}
	return (0);
}
