#!/usr/bin/python3
"""documentation"""
import math


def minOperations(n):
    """documentation"""
    res = 0
    if n > 1:
        for i in range(2, int(math.sqrt(n) + 1)):
            while n % i == 0:
                res += i
                n //= i
    return res + n if n > 1 else res
