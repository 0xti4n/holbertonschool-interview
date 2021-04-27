#!/usr/bin/python3
"""Play Prime Game"""


def isWinner(x, nums):
    """Prime game

    Args:
    -> x is the number of rounds
    -> nums is an array of n

    Returns:
    -> name of the player that won the most rounds
    """
    if not nums or x < 1:
        return None

    p1 = "Maria"
    p2 = "Ben"
    moves_p1 = 0
    zise_nums = len(nums)

    n = max(nums)

    matrix = [True for _ in range(max(n + 1, 2))]

    sqrt = int(pow(n, 0.5)) + 1
    for i in range(2, sqrt):
        if matrix[i] is False:
            continue
        for j in range(i*i, n + 1, i):
            matrix[j] = False

    matrix[0] = False
    matrix[1] = False

    u = 0
    for i in range(len(matrix)):
        if matrix[i] is True:
            u += 1
        matrix[i] = u

    for n in nums:
        moves_p1 += matrix[n] % 2 == 1

    if moves_p1 * 2 == zise_nums:
        return None

    if moves_p1 * 2 > zise_nums:
        return p1

    return p2
