#include "main.h"

/**
 * clear_infos - Entry point
 * Description: A function that initialize the struct infos_t
 *
 * @info: a pointer to struct address
 * Return: Nothing.
 */

void clear_infos(infos_t *info)
{
	info->path = NULL;
	info->args = NULL;
	info->argv = NULL;
	info->argc = 0;
}

/**
 * free_infos - Entry point
 * Description: A function that frees memory of infos_t struct fields
 *
 * @info: struct address (a pointer)
 * @entire: all field
 * Return: nothing.
 */

void free_infos(infos_t *info, int entire)
{
	sfree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (entire)
	{
		if (info->cmd_buff)
			free(info->args);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		sfree(info->environ);
		info->environ = NULL;
		buffree((void **)info->cmd_buff);
		if (info->read_fd > 2)
			close(info->read_fd);
		_putchar(BUFF_FLUSH);
	}
}

/**
 * set_infos - Entry point
 * Description: A function that set information on the struct address.
 *
 * @info: pointer of address from struct
 * @av: argument vector.
 * Return: nothing.
 */

void set_infos(infos_t *info, char **av)
{
	int a = 0;

	info->file_name = av[0];
	if (info->args)
	{
		info->argv = token(info->args, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->args);
				info->argv[1] = NULL;
			}
		}
		for (a = 0; info->argv && info->argv[a]; ++a)
			;
		info->argc = a;

		ralias(info);
		rvars(info);
	}
}

/**
 * delete_commentary - Entry point
 * @buff: the specific pointer of the string to be appended.
 * Description: function that replace '#' with '\0'.
 *
 * Return: Nothing.
 */
void delete_commentary(char *buff)
{
	int a;

	for (a = 0; buff[a] != '\0'; ++a)
		if (buff[a] == '#' && (!a || buff[a - 1] == ' '))
		{
			buff[a] = '\0';
			break;
		}
}
