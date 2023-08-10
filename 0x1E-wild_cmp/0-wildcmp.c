#include "holberton.h"

/**
 * wildcmp - compares two strings with wildcard
 * @s1: first string
 * @s2: second string
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcompare(s1, s2, 0));
}

/**
 * wildcompare - recursive string compare with wildcard
 * @s1: first string
 * @s2: second string
 * @wildcard: wildcard flag
 * Return: 1 if identical, 0 otherwise
 */
int wildcompare(char *s1, char *s2, int wildcard)
{
	size_t back_count = 0;

	if (s1 && s2 == NULL)
		return (1);
	if (s1 == NULL)
		return (0);
	if (s2 == NULL)
		return (0);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	if (s2[0] == '*')
	{
		wildcard = 1;
		s2 = forward_wildcard(s2);
		s1 = forward_to_char(s1, s2[0]);
		return (wildcompare(s1, s2, wildcard));
	}
	if (s1[0] != s2[0] && wildcard)
	{
		back_count = backward_wildcard(s2, 0);
		s2 -= back_count;
		s1 -= back_count;
		if (s1[0] == '\0' || s1[1] == '\0')
			return (0);
		s1 += 2;
		return (wildcompare(s1, s2, wildcard));
	}
	else if (s1[0] != s2[0])
		return (0);
	s1++;
	s2++;
	return (wildcompare(s1, s2, wildcard));
}

/**
 * forward_wildcard - moves past wildcard chars
 * @s2: second string
 * Return: new pointer past wildcards
 */
char *forward_wildcard(char *s2)
{
	if (s2[0] == '*')
	{
		s2++;
		return (forward_wildcard(s2));
	}
	return (s2);
}

/**
 * forward_to_char - moves to next matching char or null byte
 * @s1: first string
 * @c: character to match
 * Return: new pointer at matching char or null byte
 */
char *forward_to_char(char *s1, char c)
{
	if (s1[0] != c && s1[0] != '\0')
	{
		s1++;
		return (forward_to_char(s1, c));
	}
	return (s1);
}

/**
 * backward_wildcard - counts chars since last wildcard
 * @s2: second string
 * @back_count: count of chars moving backwards to wildcard
 * Return: count of chars since last wildcard
 */
size_t backward_wildcard(char *s2, size_t back_count)
{
	if (s2[0] != '*')
	{
		s2--;
		back_count++;
		return (backward_wildcard(s2, back_count));
	}
	return (back_count);
}
