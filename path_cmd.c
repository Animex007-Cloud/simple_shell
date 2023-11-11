#include "main.h"

/**
 * _iscmd - Entry point
 * @info: the parameter containinf arguments.
 * @path: path of the file.
 *
 * Description: functions that check if the file is an executable command.
 * Return: 1 if executable is true, 0 if false.
 */
int _iscmd(infos_t *info, char *path)
{
	struct stat var;

	(void)info;
	if (!path || stat(path, &var))
		return (0);

	if (var.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * chars_x - Entry point
 * @str: the path string
 * @index: the starting point
 * @halt: the stopping point
 *
 * Description: function that duplicates the characters x num of times.
 * Return: the pointer to a new buffer.
 */
char *chars_x(char *str, int index, int halt)
{
	static char buff[1024];
	int a, b = 0;

	for (b = 0, a = index; a < halt; ++a)
		if (str[a] != ':')
			buff[++b] = str[a];
	buff[b] = 0;
	return (buff);
}

/**
 * f_path - Entry point
 * @info: the parameter that contains arguments.
 * @str: the path string.
 * @cmd: the command to search.
 *
 * Description: function that finds cmd in the PATH string.
 * Return: the full path of the cmd if found successfully,
 * NULL if not found,
 */
char *f_path(infos_t *info, char *str, char *cmd)
{
	int a, b = 0;
	char *path;

	if (!str)
		return (NULL);
	if ((_strlen(cmd) > 2) && init(cmd, "./"))
	{
		if (_iscmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!str[a] || str[a] == ':')
		{
			path = chars_x(str, b, a);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (_iscmd(info, path))
				return (path);
			if (!str[a])
				break;
			b = a;
		}
		++a;
	}
	return (NULL);
}
