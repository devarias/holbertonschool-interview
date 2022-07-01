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

    coins.sort(reverse=True)
    ad = 0
    noCoins = 0
    cnt = 0

    while cnt < len(coins) and ad != total:
        if ad + coins[cnt] > total:
            cnt += 1
        else:
            ad += coins[cnt]
            noCoins += 1
    if ad == total:
        return noCoins
    return -1
