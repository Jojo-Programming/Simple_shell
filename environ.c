#include "shell.h"

/**
* _myenv – Current environment is displayed
* @info: Structure holding potential arguments
* Used to maintain constant function prototype.
*
* By :Jojo-Programming
* Return: Always 0
*/

	int _myenv(info_t *info)
{
	print_list_str(info->env);


	return (0);
}

/**
* _getenv – value of an environ variable is
* acqured
* @info: Structure holding potential argument
* used to maintain constant function prototype
* @name:var name of env
*
* By : Jojo-Programming
* Return: the value
*/

	char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	size_t name_len = strlen(name);
	char *p;

	while (node)
{
	if (strncmp(node->str, name, name_len) == 0 && node->str[name_len] == '=')
{
	p = node->str + name_len + 1;

	return (*p != '\0' ? p : NULL);
}
	node = node->next;
}

	return (NULL);
}


/**
* _mysetenv – Initialize a new environment
* variable and modify an existing one
* @info: structure that contains potential
*  arguments used to maintain constant function
* prototype.
*  Return: Always 0
*/

	int _mysetenv(info_t *info)
{
	if (info->argc != 3)
{
	_eputs("Wrong number of arguements\n");

	return (1);
}
	if (_setenv(info, info->argv[1], info->argv[2]))
	return (0);

	return (1);
}

/**
* _myunsetenv – eliminates an environment
* variable
* @info: structure holding  potential
* arguments used to maintain
* constant function prototype.
* Return: Always 0
*/

	int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
{
	_eputs("Not enough arguements.\n");

	return (1);
}
	for (i = 1; i <= info->argc; i++)
	_unsetenv(info, info->argv[i]);

return (0);
}

/**
* populate_env_list – occupies env linked lists.
* @info: structure that contains potential
* arguments, used to maintain
* constant function prototype.
* Return: Always 0
*/

	int populate_env_list(info_t *info)
{
	list_t *node = 0;
	size_t i;

	for (i = 0; environ[i]; i++)
	add_node_end(&node, environ[i], 0);
	info->env = node;

	return (0);
}
