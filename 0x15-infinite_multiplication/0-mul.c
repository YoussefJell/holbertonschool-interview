#include "holberton.h"
/**
 * multiply - infinite multiplication using bc
 *
 * @num1: integer
 * @num2: integer
 * Return: void
 */
void multiply(const char *num1, const char *num2)
{
	int len1 = 0, c, len2 = 0;
	int maxLen = len1 + len2 + 16;
	char *command;
	FILE *pipe;

	while (num1[len1] != '\0')
		len1++;

	while (num2[len2] != '\0')
		len2++;

	command = (char *)malloc(maxLen * sizeof(char));
	if (command == NULL)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}
	snprintf(command, maxLen, "echo '%s * %s' | bc", num1, num2);
	pipe = popen(command, "r");
	if (pipe == NULL)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}
	while ((c = getc(pipe)) != EOF)
	{
		_putchar(c);
	}
	pclose(pipe);
	free(command);
}
/**
 * main - main func
 *
 * @argc: argc
 * @argv: argv
 * Return: integer 98 if error 0 if success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}

	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				_putchar('E');
				_putchar('r');
				_putchar('r');
				_putchar('o');
				_putchar('r');
				_putchar('\n');
				return (98);
			}
		}
	}

	multiply(argv[1], argv[2]);

	return (0);
}
