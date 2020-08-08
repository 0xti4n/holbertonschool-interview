#!/usr/bin/python3
"""Minimum operations"""


def minOperations(n):
    """Function that calculates
    minimum operations"""
    H = 1
    copy_all = 0
    con = 0
    if type(n) is not int or n < 2:
        return 0

    for i in range(n):
        if H == n:
            return con
        if n % H == 0:
            copy_all = H
            H += copy_all
            con += 2
        else:
            H += copy_all
            con += 1
