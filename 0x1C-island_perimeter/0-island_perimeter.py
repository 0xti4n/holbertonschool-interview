#!/usr/bin/python3
"""Island perimeter"""


def island_perimeter(grid):
    """perimeter of the island described in grid:

    Args:
    -> grid is a list of list of integers

    Returns:
    -> the perimeter of the island
    """
    g = grid
    lis = []
    per = 0
    if len(g) < 100:
        for x in range(len(g)):
            if len(g[x]) < 100:
                for y in range(len(g[x])):
                    if (g[x][y] == 1):
                        per = 4
                        if (g[x - 1][y] == 1 and x > 0):
                            per -= 1
                        if ((x + 1) <= len(g) - 1 and g[x + 1][y] == 1):
                            per -= 1
                        if ((y + 1) <= len(g[x]) - 1 and g[x][y + 1] == 1):
                            per -= 1
                        if (g[x][y - 1] == 1 and y > 0):
                            per -= 1
                        lis.append(per)
    return (sum(lis))
