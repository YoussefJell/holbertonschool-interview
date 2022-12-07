#!/usr/bin/python3
"""module 0"""


def canUnlockAll(boxes):
    """func"""
    unlocked_boxes = [0]
    for i, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key != i and key not in unlocked_boxes:
                unlocked_boxes.append(key)
    if len(unlocked_boxes) == len(boxes):
        return True
    return False
