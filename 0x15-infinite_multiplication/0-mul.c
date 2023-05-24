#include "holberton.h"
/**
 * _isdigit - Checks digit
 * @c: The character to be checked
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Computes the length of a string
 * @str: string
 *
 * Return: length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * print_error_and_exit - Prints an error
 */
void print_error_and_exit(void)
{
	char *error = "Error\n";
	int len = _strlen(error);
	int i;

	for (i = 0; i < len; i++)
		_putchar(error[i]);
	exit(98);
}

/**
 * multiply - Multiplies two numbers
 * @num1: string
 * @num2: string
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, result_len, *result, i, j, n1, n2, sum, carry;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result_len = len1 + len2;
	result = malloc(sizeof(int) * result_len);
	if (result == NULL)
		print_error_and_exit();
	for (i = 0; i < result_len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		if (!_isdigit(num1[i]))
			print_error_and_exit();
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			if (!_isdigit(num2[j]))
			{
				free(result);
				print_error_and_exit();
			}
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result[i] += carry;
	}
	if (result[0] == 0)
		i = 1;
	else
		i = 0;
	for (; i < result_len; i++)
		_putchar(result[i] + '0');
	_putchar('\n');
	free(result);
	exit(0);
}

/**
 * main - Entry point
 * @argc: argc
 * @argv: argv
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error_and_exit();

	multiply(argv[1], argv[2]);
	return (0);
}
