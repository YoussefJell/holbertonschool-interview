#include "sandpiles.h"

/**
 * grid_add - adds grid
 * @grid1: grid1
 * @grid2: grid2
 * Return: void function
 */
void grid_add(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}



/**
 * isGridStable - stability of sandpile
 * @grid1: grid
 * Return: void function
 */
int isGridStable(int grid1[3][3])
{

	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				return (0);
	return (1);
}

/**
 * print_grid - displays grid
 * @grid: grid
 * Return: void function
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * tupple_grid - tupples the sands
 * @grid1: grid
 * Return: void function
 */
void tupple_grid(int grid1[3][3])
{
	int i;
	int j;
	int new_grid[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			new_grid[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					new_grid[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					new_grid[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					new_grid[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					new_grid[i][j + 1] += 1;
			}
		}
	}

	grid_add(grid1, new_grid);
}
/**
 * sandpiles_sum - summarize sandpile
 * @grid1: grid1
 * @grid2: grid2
 * Return: void function
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	grid_add(grid1, grid2);

	while (isGridStable(grid1) == 0)
	{
		print_grid(grid1);
		tupple_grid(grid1);
	}

}

