#include "shell.h"

/**
 * list_len Determines length of linked list
 * @h: pointer to the first node
 *
 * By : Jojo-Programming
 * Return: size of list
 */

	size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
{
	h = h->next;
	i++;
}
	return (i);
}

/**
 * list_to_strings - Returns an array of
 * strings of the list->str
 * @head: Pointer to the first node
 *
 *
 * Return: array of strings
 */

	char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
	return (0);

	strs = malloc(sizeof(char *) * (i + 1));

	if (!strs)
	return (0);

	for (i = 0; node; node = node->next, i++)
{
	str = malloc(_strlen(node->str) + 1);
	if (!str)
{
	for (j = 0; j < i; j++)
	free(strs[j]);
	free(strs);
	return (0);
}

	str = _strcpy(str, node->str);
	strs[i] = str;
}
	strs[i] = 0;
	return (strs);
}


/**
 * print_list - function prints all elements
 * of a list_t linked list
 * @h: pointer to begining node
 *
 *
 * Return: list size
 */

	size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
{
	_puts(convert_number(h->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(h->str ? h->str : "(nil)");
	_puts("\n");
	h = h->next;
	i++;
}
	return (i);
}

/**
 * node_starts_with - Returns node whose string
 * starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: Next character after prefix to go with
 *
 * By : Jojo-Programming
 * Return: match node or 0
 */

	list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;
	size_t prefix_len = strlen(prefix);

	while (node)
{
	char *str = node->str;
	size_t str_len = strlen(str);

	if (str_len >= prefix_len && strncmp(str, prefix, prefix_len) == 0)
{
	p = str + prefix_len;

	if (c == 1 || (*p == c))
	return (node);
}
	node = node->next;
}
	return (NULL);
}


/**
 * get_node_index - Fetches the index of a node
 * @head: pointer to head of list
 * @node: pointer to node
 *
 *
 * Return: node index or -1
 */

	ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
{
	if (head == node)
	return (i);
	head = head->next;
	i++;
}
	return (-1);
}
