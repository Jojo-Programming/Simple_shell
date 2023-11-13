#include "shell.h"

/**
 * get_environ – Returns string array copy of
 * the environ
 * @info: The structure that contains potential
 * arguments used to maintain constant function
 *  prototype.
 *
 *  By : Jojo-Programming
 * Return: Always 0
 */

	char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
{
	info->environ = list_to_strings(info->env);
	info->env_changed = 0;
}

	return (info->environ);
}

/**
 * _unsetenv - function which unsets an
 *  environmental variable
 * @info: Pointer to info_t struct
 * @var: Pointer to char variable
 *
 *
 * Return: 0 on success, -1 on failure
 */

	int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;

	size_t i = 0;

	char *p;

	if (!node || !var)
	return (0);

	while (node)
{
	p = strchr(node->str, '=');
	if (p && strncmp(node->str, var, p - node->str) == 0)
{
	info->env_changed = delete_node_at_index(&(info->env), i);
	i = 0;
	node = info->env;
	continue;

}
	node = node->next;
	i++;
}
	return (info->env_changed);
}

/**
 * _setenv - function that sets environmental
 * variable
 * @info: Pointer to info_t struct
 * @var: Pointer to char variable
 * @value: Pointer to char variable
 *
 *
 * Return: 0 always
 */

	int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
	return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);

	if (!buf)
	return (1);

	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);

	node = info->env;
	while (node)
{
	p = strchr(node->str, '=');
	if (p && strncmp(node->str, var, p - node->str) == 0)
{
	free(node->str);

	node->str = buf;

	info->env_changed = 1;

	return (0);
}

	node = node->next;
}

	add_node_end(&(info->env), buf, 0);

	free(buf);

	info->env_changed = 1;

	return (0);
}
