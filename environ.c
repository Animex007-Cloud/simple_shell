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
