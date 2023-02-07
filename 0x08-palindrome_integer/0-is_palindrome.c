#include "palindrome.h"
/**
 * is_palindrome - checks if n is palindrome
 *
 * @n: integer to check
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long tmp = n;
	unsigned long reverse = 0;
	while (tmp > 0)
	{
		reverse *= 10;
		reverse += tmp % 10;
		tmp /= 10;
	}

	return (reverse == n);
}
