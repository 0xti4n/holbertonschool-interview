#!/usr/bin/python3
"""returns a list of lists of integers
representing the Pascal triangle of n
"""


def pascal_triangle(n):
    """function"""
    if n <= 0:
        return []
    a = []
    for i in range(n):
        l1 = []
        l1.append(1)
        if i:
            for j in range(1, i):
                l1.append(a[i - 1][j - 1] + a[i - 1][j])
            l1.append(1)
        a.append(l1)
    return a
