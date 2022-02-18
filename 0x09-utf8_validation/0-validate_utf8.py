#!/usr/bin/python3
""" module docs """


def validUTF8(data):
    """ method docs """
    c = 0
    for n in data:
        m = 0b10000000
        if not c:
            while (m & n):
                c += 1
                m >>= 1
            if c > 4:
                return False
            if c:
                c -= 1
                if c == 0:
                    return False
        elif c > 0:
            if n >> 6 != 2:
                return False
            c -= 1
    return not c
