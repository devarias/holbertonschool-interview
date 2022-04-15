#!/usr/bin/python3
"""
module docs
"""


def rain(walls):
    """
    method docs
    """
    l = len(walls)
    total = 0

    for i in range(1, l - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, l):
            right = max(right, walls[j])
        total = total + (min(left, right) - walls[i])
    return total
