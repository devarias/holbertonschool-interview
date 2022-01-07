#!/usr/bin/python3
import math


def minOperations(n):
    """ a method that calculates the fewest number of
        operations needed to result in exactly n H characters in the file.
    """
    res = 0
    if n > 1:
        for i in range(2, int(math.sqrt(n) + 1)):
            while n % i == 0:
                res += i
                n //= i
    return res + n if n > 1 else res

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))