#!/usr/bin/env python3
import sys


count = 1
statusCodeMap = {}
fileSizes = []


def recap(codeMap, fileSizes):
    print('File size: {}'.format(fileSizes))
    for key, val in sorted(codeMap.items()):
        print('{}: {}'.format(key, val))


try:
    for line in sys.stdin:
        newList = line.split(" ")
        try:
            fileSizes.append(int(newList[-1]))
        except:
            continue
        statusCodeMap[newList[-2]] = statusCodeMap.get(newList[-2], 0) + 1
        if count % 10 == 0:
            recap(statusCodeMap, sum(fileSizes))
            statusCodeMap = {}
            fileSizes = []
        count += 1
except KeyboardInterrupt:
    recap(statusCodeMap, sum(fileSizes))
    raise
