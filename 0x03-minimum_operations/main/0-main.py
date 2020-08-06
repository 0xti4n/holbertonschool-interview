#!/usr/bin/python3
"""
Main file for testing
"""

"""
example:
n = 9

H => Copy All => Paste => HH => Paste =>HHH
=> Copy All => Paste => HHHHHH => Paste => HHHHHHHHH
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 12
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))
