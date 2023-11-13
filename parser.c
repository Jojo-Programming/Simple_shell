#include "shell.h"

/**
 * is_cmd - Determines if a file is a excutable
 * command
 * @path: Path to the file
 * @info: Info struct
 *
 * Jojo-Programming
 * Return: 1 if true, 0 otherwise
 */

	int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;

	if (!path || stat(path, &st))
	return (0);

	if (st.st_mode & S_IFREG)
{
	return (1);
}
	return (0);
}

/**
 * dup_chars - Duplicates characters
 * @pathstr: PATH string
 * @stop: stopping index.
 * @start: Starting index.
 *
 * By : Jojo-Programming
 * Return: A pointer to new buffer
 */

	char *dup_chars(char *pathstr, int start, int stop)
{
	int i = 0, k = 0;
	static char buf[1024];

	for (k = 0, i = start; i < stop; i++)

	if (pathstr[i] != ':')
	buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - Finds the cmd in the PATH string
 * @cmd: cmd to find
 * @info: info struct
 * @pathstr: PATH string
 *
 * By : Jojo-Programming
 * Return: full path of cmd if found or NULL
 */

	char *find_path(info_t *info, char *pathstr, char *cmd)
{
	char *path;
	int i = 0, curr_pos = 0;

	if (!pathstr)
	return (NULL);

	if ((_strlen(cmd) > 2) && (cmd[0] == '.' && cmd[1] == '/'))
{
	if (is_cmd(info, cmd))
	return (cmd);
}

	while (1)
{
	if (!pathstr[i] || pathstr[i] == ':')
{
	path = dup_chars(pathstr, curr_pos, i);
	if (!*path)
{
	_strcat(path, cmd);
}
	else
{
	_strcat(path, "/");
	_strcat(path, cmd);
}
	if (is_cmd(info, path))
	return (path);

	if (!pathstr[i])
	break;
	curr_pos = i + 1;
}
	i++;
}

	return (NULL);
}
