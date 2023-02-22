#include "slide_line.h"
/**
 * slide_left - slides array to left
 *
 * @line: the array to slide
 * @size: the size of the array
 * Return: void
 */
void slide_left(int *line, size_t size)
{
	int i, j;

	for (i = 0; i < (int)size; i++)
	{
		if (line[i] == 0)
			continue;
		for (j = i + 1; j < (int)size; j++)
		{
			if (line[j] == 0)
				continue;
			if (line[i] == line[j])
			{
				line[i] *= 2;
				line[j] = 0;
				break;
			}
			else
				break;
		}
	}
	for (i = 0, j = 0; i < (int)size; i++)
	{
		if (line[i] != 0)
			line[j++] = line[i];
	}
	for (i = j; i < (int)size; i++)
		line[i] = 0;
}

/**
 * slide_right - slides array to right
 *
 * @line: the array to slide
 * @size: the size of the array
 * Return: void
 */
void slide_right(int *line, size_t size)
{
	int i, j;

	for (i = (int)size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			continue;
		for (j = i - 1; j >= 0; j--)
		{
			if (line[j] == 0)
				continue;
			if (line[i] == line[j])
			{
				line[i] *= 2;
				line[j] = 0;
				break;
			}
			else
				break;
		}
	}
	for (i = (int)size - 1, j = (int)size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
			line[j--] = line[i];
	}
	for (i = j; i >= 0; i--)
		line[i] = 0;
}

/**
 * slide_line - slides array like in 2048 game horizontal only
 *
 * @line: the array to slide
 * @size: the size of the array
 * @direction: direction to slide in
 * Return: 0 if failed 1 if success
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size < 1 ||
		(direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
	{
		return (0);
	}
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
	}
	else
	{
		slide_right(line, size);
	}
	return (1);
}
