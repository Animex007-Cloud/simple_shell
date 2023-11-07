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
