#!/usr/bin/python3
""" rain module """
def rain(walls):
    """ Coment """
    n = len(walls)
    if n == 0:
        return 0
    left_max = [0] * n
    right_max = [0] * n
    left_max[0] = walls[0]
    right_max[n-1] = walls[n-1]
    for i in range(1, n):
        left_max[i] = max(left_max[i-1], walls[i])
    for i in range(n-2, -1, -1):
        right_max[i] = max(right_max[i+1], walls[i])
    water = 0
    for i in range(n):
        water += min(left_max[i], right_max[i]) - walls[i]
    return water
