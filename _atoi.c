#include "shell.h"

/**
 * interactive -Returns true if shell is
 * interactive mode
 * @info: address of struct
 *
 * By :Jojo-Programming
 * Return: 1 if interactive mode, 0 if not
 */

	int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Function checks if character is
 * a delimeter
 * @c: char to check
 * @delim: Astring delimeter
 * Return: 1 if true and  0 if otherwise
 */

	int is_delim(char c, char *delim)
{
	while (*delim)

	if (*delim++ == c)
	return (1);

	return (0);
}

/**
 *_isalpha - function checks for alphabetic
 *  character
 *@c: character to input
 *Return: 1 if c is alphabetic, 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	return (1);
	else
	return (0);
}

/**
 * _atoi - Converts a string to integer
 * @s: string to be converted
 * Return: 0 if no number is in string and
 * converted number otherwise
 */

	int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;

	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
{
	if (s[i] == '-')
	sign *= -1;

	if (s[i] >= '0' && s[i] <= '9')
{
	flag = 1;
	result *= 10;
	result += (s[i] - '0');
}
	else if (flag == 1)
	flag = 2;
}

	if (sign == -1)
	output = -result;

	else
	output = result;

	return (output);
}
