#include "main.h"

/**
 * env_list - Entry point
 * @info: contains arguments.
 *
 * Description: populates the env  linked list.
 * Return: Always 0 (On success)
 */
int env_list(infos_t *info)
{
	list_t *node = NULL;
	size_t n;

	for (n = 0; environ[n]; ++n)
		plus_node_last(&node, environ[n], 0);
	info->env = node;
	return (0);
}

/**
 * get_env - Entry point
 * @info: parameter that contains arguments.
 * @moniker: env name
 *
 * Description: gets value from an environ.
 * Return: the value of env when successful,
 * NULL if no value exit.
 */
char *get_env(infos_t *info, const char *moniker)
{
	list_t *node = info->env;
	char *c;

	while (node)
	{
		c = init(node->str, moniker);
		if (c && *c)
			return (c);
		node = node->next;
	}
	return (NULL);
}

/**
 * my_env - Entry point
 * @info: parameter that contains argument.
 *
 * Description: function that prints the current environment.
 * Return: Always 0 (On Success).
 */
int my_env(infos_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * my_unsetenv - Entry point
 * @info: the parameter that contains argument.
 *
 * Description: functions that removes an environment variable.
 * Return: Always 0 (On sucess)
 */
int my_unsetenv(infos_t *info)
{
	int a;

	if (info->argc == 1)
	{
		_puts("Too few arguments.\n");
		return (1);
	}
	for (a = 1; a <= info->argc; ++a)
		unset_env(info, info->argv[a]);

	return (0);
}

/**
 * my_setenv - Entry point
 * @info: contains parameter argument.
 *
 * Description: set a new environment variable or change value
 * of an existing one.
 *
 * Return: Always 0 (On Success)
 */
int my_setenv(infos_t *info)
{
	if (info->argc != 3)
	{
		_puts("Incorrect number of arguments.\n");
		return (1);
	}
	if (set_env(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
