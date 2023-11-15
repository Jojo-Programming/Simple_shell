#include "shell.h"

/**
 * strtow - Seperates a string into words and
 * repeated delimeters are ignored
 * @d: String delimeter
 * @str: An input string.
 *
 * By : Jojo-Programming
 * Return: A pointer to an array of strings and
 * NULL when fail
 */

	char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == 0 || str[0] == 0)
	return (0);

	if (!d)
	d = " ";

	for (i = 0; str[i] != '\0'; i++)
	if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
	numwords++;

	if (numwords == 0)
	return (0);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
	return (0);

	for (i = 0, j = 0; j < numwords; j++)
{
	while (is_delim(str[i], d))
	i++;
	k = 0;
	while (!is_delim(str[i + k], d) && str[i + k])
	k++;
	s[j] = malloc((k + 1) * sizeof(char));
	if (!s[j])
{
	for (k = 0; k < j; k++)
	free(s[k]);
	free(s);
	return (0);
}
	for (m = 0; m < k; m++)
	s[j][m] = str[i++];
	s[j][m] = 0;
}
	s[j] = 0;
	return (s);
}
/**
 *strtow2 - Seperates a string into words
 * @d: delimeter string
 * @str: String input
 * Return: A pointer to an array of strings and
 * or NULL wheb fails.
 */

	char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == 0 || str[0] == 0)
	return (0);

	for (i = 0; str[i] != '\0'; i++)
	if ((str[i] != d && str[i + 1] == d) ||
	(str[i] != d && !str[i + 1]) || str[i + 1] == d)
	numwords++;

	if (numwords == 0)
	return (0);

	s = malloc((1 + numwords) * sizeof(char *));

	if (!s)
	return (0);

	for (i = 0, j = 0; j < numwords; j++)
{
	while (str[i] == d && str[i] != d)
	i++;
	k = 0;
	while (str[i + k] != d && str[i + k] && str[i + k] != d)
	k++;
	s[j] = malloc((k + 1) * sizeof(char));
	if (!s[j])
{
	for (k = 0; k < j; k++)
	free(s[k]);
	free(s);
	return (NULL);
}
	for (m = 0; m < k; m++)
	s[j][m] = str[i++];
	s[j][m] = 0;
}
	s[j] = NULL;
	return (s);
}
