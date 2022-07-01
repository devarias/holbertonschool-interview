#!/usr/bin/python3
"""
module doc
"""


def makeChange(coins, total):
    """
    function doc
    """
    if total <= 0:
        return 0
    ct = 0
    coins.sort(reverse=True)
    for value in coins:
        tmp = int(total / value)
        total -= tmp * value
        ct += tmp
        if total == 0:
            return ct
    if total != 0:
        return -1
