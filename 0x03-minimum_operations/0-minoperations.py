#!/usr/bin/python3
"""
minop
"""
def minOperations(n):
	"""
	comment
	"""
	if n <= 1:
		return 0
	div = 2
	ops = 0

	while n > 1:
		if n % div == 0:
			n = n / div
			ops = ops + div
		else:
			div += 1
	return ops
