#!/usr/bin/python3
"""Make Change coins"""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine
    the fewest number of coins needed to meet a given amount

    Args:
    -> coins: is a list of the values of the coins in your possession

    return:
    -> total: fewest number of coins needed to meet a given amount total
    """
    n_coins = 0

    if total <= 0:
        return n_coins

    coins.sort(reverse=True)

    while (total > 0 and coins):
        n = int(total / coins[0])
        total = total - (coins[0] * n)
        n_coins = n_coins + n
        coins.remove(coins[0])

    if total != 0:
        return -1

    return n_coins
