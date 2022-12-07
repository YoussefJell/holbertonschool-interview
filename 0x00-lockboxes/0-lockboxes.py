#!/usr/bin/python3
"""module 0"""


def canUnlockAll(boxes):
    """func"""
    unlocked = list(boxes[0])

    for i in range(0, len(boxes) - 1):
        for key in boxes[i]:
            for elem in boxes[key]:
                unlocked.append(elem)
    if 0 in unlocked:
        if len(set(unlocked)) == len(boxes):
            return True
    else:
        if len(set(unlocked)) == len(boxes) - 1:
            return True
    return False
