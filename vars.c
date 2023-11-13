#include "shell.h"

/**
 * is_chain : To test if the current char in
 * buffer is a chain delimeter
 * @p: Address of the current position in buf
 * @info: parameter struct
 * @buf: char buffer
 *
 * By : Jojo-Programming
 * Return: i if chain delimeter and 0 otherwise
 */

	int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
{
	buf[j] = 0;
	j++;
	info->cmd_buf_type = CMD_OR;
}

	else if (buf[j] == '&' && buf[j + 1] == '&')
{
	buf[j] = 0;
	j++;
	info->cmd_buf_type = CMD_AND;
}

	else if (buf[j] == ';') /* found end of this command */
{
	buf[j] = 0; /* replace semicolon with null */
	info->cmd_buf_type = CMD_CHAIN;
}

	else
	return (0);

	*p = j;
	return (1);
}

/**
 * check_chain : Checks weather we should
 * continue chaining based on last status
 * @info: parameter struct
 * @p: Address of current position in buf
 * @buf: char buffer
 * @len: Length of buf
 * @i: Starting position in buf
 *
 * By : Jojo-Programming
 * Return: void
 */

	void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
{

	if (info->status)
{
	buf[i] = 0;
	j = len;
}
}
	if (info->cmd_buf_type == CMD_OR)

{
	if (!info->status)
{
	buf[i] = 0;
	j = len;
}
}
	*p = j;
}

/**
 * replace_alias : Replaces an aliases in the
 * tokenized string
 * @info: parameter struct
 *
 *
 * Return: i if replaced, 0 otherwise
 */

	int replace_alias(info_t *info)
{
	int i;
	char *p;
	list_t *node;

	for (i = 0; i < 10; i++)
{
	node = node_starts_with(info->alias, info->argv[0], '=');

	if (!node)
	return (0);

	free(info->argv[0]);
	p = _strchr(node->str, '=');

	if (!p)
	return (0);

	p = _strdup(p + 1);

	if (!p)
	return (0);

	info->argv[0] = p;
}
	return (1);
}

/**
 *  replace_vars : This replaces vars in the
 *  tokenized string
 *  @info: parameter struct
 *
 * By : Jojo-Programming
 *  Return: 1 if replaced, 0 otherwise
 */

	int replace_vars(info_t *info)
{
	list_t *node;
	int i = 0;

	for (i = 0; info->argv[i]; i++)
{
	if (info->argv[i][0] != '$' || !info->argv[i][1])
	continue;

	if (!_strcmp(info->argv[i], "$?"))
{
	replace_string(&(info->argv[i]),
	_strdup(convert_number(info->status, 10, 0)));
	continue;
}

	if (!_strcmp(info->argv[i], "$$"))
{
	replace_string(&(info->argv[i]),
	_strdup(convert_number(getpid(), 10, 0)));
	continue;
}
	node = node_starts_with(info->env, &info->argv[i][1], '=');

	if (node)
{
	replace_string(&(info->argv[i]),
	_strdup(_strchr(node->str, '=') + 1));
	continue;
}
	replace_string(&info->argv[i], _strdup(""));
}
	return (0);
}

/**
 * replace_string - Replaces a string
 * @new: a new string
 * @old: the address of old string
 *
 * By : Jojo-Programming
 * Return: 1 if the replaced, 0 otherwise
 */

	int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
