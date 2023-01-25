#!/usr/bin/python3
"""module documentation"""
import sys


count = 1
statusCodeMap = {}
fileSizes = []


def recap(codeMap, fileSizes):
    """function that recaps what has been counted"""
    print('File size: {}'.format(fileSizes))
    for key in sorted(codeMap.keys()):
        print('{}: {}'.format(key, codeMap[key]))


try:
    for line in sys.stdin:
        newList = line.split(" ")
        if len(newList) > 9 or len(newList) < 9:
            continue
        try:
            fileSizes.append(int(newList[-1]))
        except:
            continue
        statusCodeMap[newList[-2]] = statusCodeMap.get(newList[-2], 0) + 1
        if count % 10 == 0:
            recap(statusCodeMap, sum(fileSizes))
        count += 1
except KeyboardInterrupt:
    recap(statusCodeMap, sum(fileSizes))
    raise
