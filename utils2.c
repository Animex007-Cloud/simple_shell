#include "main.h"

/**
 * rmoniker - Entry point
 * Description: A function that replace entity with a tokenized string.
 *
 * @info: the struct to check and be replaced.
 * Return: 1 on success and 0 if failed
 */

int rmoniker(infos_t *info)
{
	int a;
	list_t *node;
	char *c;

	for (a = 0; a < 10; ++a)
	{
		node = node_init(info->moniker, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);

		c = _strchr(node->str, '=');
		if (!c)
			return (0);
		c = _strchr(c + 1);
		if (!c)
			return (0);
		info->argv[0] = c;
	}
	return (1);
}

/**
 * rvars - Entry point
 * Description: A function that replace vars in the tokenized string.
 *
 * @info: struct list
 * Return: 0 if fail, 1 if success.
 */

int rvars(infos_t *info)
{
	int a;
	list_t *node;

	for (a = 0; info->argv[a]; a++)
	{
		if (info->argv[a][0] != '$' || !info->argv[a][1])
			continue;

		if (!_strcmp(info->argv[a], "$?"))
		{
			rstr(&(info->argv[a]), _strdup(converter(info->stats, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[a], "$$"))
		{
			rstr(&(info->argv[a]), _strdup(convert(getpid(), 10, 0)));
			continue;
		}
		node = node_init(info->env, &info->argv[a][1], '=');
		if (node)
		{
			rstr(&(info->argv[a]), _strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		rstr(&info->argv[a], _strdup(""));
	}
	return (0);
}

/**
 * rstr - Entry point
 * Description: A function that replaces old string with a new string
 *
 * @former: belong to old string
 * @latter: belong to new string
 *
 * Return: 0 if failed, 1 if successful.
 */

int rstr(char **former, char *latter)
{
	free(*former);
	*former = latter;

	return (1);
}
