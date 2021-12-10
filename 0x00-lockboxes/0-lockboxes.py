#!/usr/bin/python3
"""0. Lockboxes"""


def canUnlockAll(boxes):
    """ Function to know if all the boxes can be unlocked"""
    keys = set()
    for next_key, box in enumerate(boxes):
        next_key += 1
        for key in box:
            if key < len(boxes):
                keys.add(key)
                keys.update(boxes[key])
            if len(keys) == len(boxes) or len(keys) == len(boxes) - 1:
                return True
        if next_key not in keys:
            return False
