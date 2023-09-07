#!/usr/bin/python3
""" Module for Prime Game """


def isWinner(x, nums):
    """Solves Prime Game"""
    if not nums or x < 1:
        return None
    n = max(nums)
    s = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not s[i]:
            continue
        for j in range(i*i, n + 1, i):
            s[j] = False

    s[0] = s[1] = False
    c = 0
    for i in range(len(s)):
        if s[i]:
            c += 1
        s[i] = c

    player1 = 0
    for n in nums:
        player1 += s[n] % 2 == 1
    if player1 * 2 == len(nums):
        return None
    if player1 * 2 > len(nums):
        return "Maria"
    return "Ben"
