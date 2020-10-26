#!/usr/bin/python3
import sys
"""N-QUEENS"""


def N_Queens(n):
    def R_queen(queens, xy_dif, xy_sum):
        n_test = len(queens)
        if n_test == n:
            result.append(queens)
            return 0
        for i in range(n):
            if i not in queens and n_test-i not in xy_dif \
                    and n_test + i not in xy_sum:
                R_queen(queens+[i], xy_dif+[n_test-i], xy_sum+[n_test+i])
    result = []
    R_queen([], [], [])
    return result

if __name__ == "__main__":
    N = sys.argv

    if len(N) > 2:
        print('Usage: nqueens N')
        exit(1)

    try:
        N = int(N[1])
    except:
        print('N must be a number')
        exit(1)

    if N < 4:
        print('N must be at least 4')
        exit(1)

    all_cases = []
    res = N_Queens(N)
    for case in res:
        all_cases = []
        for idx in range(len(case)):
            ls = [idx, case[idx]]
            all_cases.append(ls)
        print(all_cases)
