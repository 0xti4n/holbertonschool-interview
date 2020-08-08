#!/usr/bin/python3
"""Minimum operations"""


def copy_all(H, con):
    """copy all for concat"""
    copy = H
    con += 1
    return con, copy


def paste(copy, H, con):
    """concat the copy"""
    paste = copy + H
    con += 1
    return con, paste


def minOperations(n):
    """Function that calculates
    minimum operations"""
    H = 'H'
    con = 0
    if type(n) is not int or n < 2:
        return 0

    for i in range(n):
        if len(H) == n:
            return con
        if n % len(H) == 0:
            con1, copy = copy_all(H, con)
            con, H = paste(copy, H, con1)
        else:
            con, H = paste(copy, H, con)
    return con
