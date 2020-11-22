#!/usr/bin/python3
"""RAIN"""


def rain(walls):
    """calculate how much water will
    be retained after it rains
    """
    if len(walls) == 0:
        return 0

    stack = []
    water = 0
    i = 0
    while i < len(walls):
        if len(stack) == 0 or walls[stack[-1]] >= walls[i]:
            stack.append(i)
            i += 1
        else:
            x = stack[-1]
            stack.pop()
            if len(stack) != 0:
                temp = min(walls[stack[-1]], walls[i])
                dist = i - stack[-1] - 1
                water += dist * (temp - walls[x])
    return water
