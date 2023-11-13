#include "shell.h"

/**
 * _strcpy - Copies a string
 * @src: String source
 * @dest: String Destination
 *
 * By : Jojo-Programming
 * Return: A pointer to the destination string
 */

	char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
	return (dest);

	while (src[i])
{
	dest[i] = src[i];
	i++;
}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicates a string
 * @str: A string to be duplicated
 *
 * By : Jojo-Programming
 * Return: Pointer to the duplicated string
 */

	char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == 0)
	return (0);

	while (*str++)
	length++;

	ret = malloc(sizeof(char) * (length + 1));

	if (!ret)
	return (0);

	for (length++; length--;)
	ret[length] = *--str;

	return (ret);
}

/**
 * _puts - prints a string
 * @str: string to be printed
 *
 * By : Jojo-Programming
 * Return: Nothing
 */

	void _puts(char *str)
{
	int i = 0;

	if (!str)
	return;

	while (str[i] != '\0')
{
	_putchar(str[i]);
	i++;
}
}

/**
 * _putchar - prints the character 'c' to stdout
 * @c: character to print
 *
 * By : Jojo-Programming
 * Return: On success 1, On error, -1 is
 *  returned and errno is set appropriately.
 */

	int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
	write(1, buf, i);
	i = 0;
}

	if (c != BUF_FLUSH)
	buf[i++] = c;

	return (1);
}
