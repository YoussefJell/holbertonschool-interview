#include "regex.h"
/**
 * regex_match - looks for pattern in string
 * @str: string
 * @pattern: regex
 *
 * Return: 1 if match, 0 if not
 */
int regex_match(char const *str, char const *pattern)
{
	unsigned int i = 0, j = 0;

	for (i = 0, j = 0; str[i]; i++, j++)
	{
		if (str[i] == pattern[j])
			continue;
		else if (pattern[j] == '.')
			continue;
		else if (pattern[j] == '*')
		{
			if (pattern[j - 1] == '.')
			{
				while (pattern[j + 1] != str[i] && str[i])
					i++;
			}
			else
			{
				while (pattern[j - 1] == str[i])
					i++;
			}
			i--;
		}
		else if (pattern[j + 1] && pattern[j + 1] == '*')
			i--;
		else
			return (0);
	}
	return (1);
}
