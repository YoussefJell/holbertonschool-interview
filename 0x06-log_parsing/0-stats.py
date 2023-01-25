#!/usr/bin/env python3
import sys


def recap(codeMap, fileSize):
    print('File size: {}'.format(fileSize))
    for key, val in sorted(codeMap.items()):
        print('{}: {}'.format(key, val))


count = 1
statusCodeMap = {}
fileSizes = []
for line in sys.stdin:
    newList = line.split(" ")
    fileSizes.append(int(newList[-1]))
    statusCodeMap[newList[-2]] = statusCodeMap.get(newList[-2], 0) + 1
    if count % 10 == 0:
        fileSize = sum(fileSizes)
        recap(statusCodeMap, fileSize)
        statusCodeMap = {}
        fileSizes = []
    count += 1
