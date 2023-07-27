#!/usr/bin/python3
""" Island perimiter module """


def island_perimeter(grid):
    """ returns the perimeter of the island described """

    rows = len(grid)
    cols = len(grid[0])

    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                neighbors = 0
                if i - 1 >= 0 and grid[i - 1][j] == 0:
                    neighbors += 1
                if i + 1 < rows and grid[i + 1][j] == 0:
                    neighbors += 1
                if j - 1 >= 0 and grid[i][j - 1] == 0:
                    neighbors += 1
                if j + 1 < cols and grid[i][j + 1] == 0:
                    neighbors += 1

                perimeter += neighbors

        return perimeter
