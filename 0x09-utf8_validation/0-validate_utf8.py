#!/usr/bin/python3
def validUTF8(data):
    """ validates utf 8 """
    count = 0
    for c in data:
        if (count == 0):
            if (c == 0b11000000):
                count = 1
            elif (c == 0b11100000):
                count = 2
            elif (c == 0b11110000):
                count = 3
            elif ((c >> 7)):
                return False
        else:
            if (c != 0b10000000):
                return False
            count -= 1

    return count == 0
