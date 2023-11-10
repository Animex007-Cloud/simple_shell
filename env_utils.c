#include "main.h"

/**
 * set_env - Entry point
 * @info: parameter that contains arguments.
 * @a: th env var property.
 * @b: the env var value.
 *
 * Description: set a new environment variable.
 * Return: Always 0 (On Success)
 */
int set_env(infos_t *info, char *a, char *b)
{
	char *buff = NULL;
	list_t *node;
	char *ptr;

	if (!a || !b)
		return (0);

	buff = malloc(_strlen(a) + _strlen(b) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, a);
	_strcpy(buff, "=");
	_strcat(buff, b);
	node = info->env;

	while (node)
	{
		ptr = init(node->str, a);
		if (ptr && *ptr == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	plus_node_last(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}

/**
 * unset_env - Entry point
 * @info: parameter containing likely arguments.
 * @a: env var property.
 *
 * Description: function that deletes the environment variable.
 * Return: 1 on Successful delete, 0 if failed.
 */
int unset_env(infos_t *info, char *a)
{
	size_t c = 0;
	char *ptr;
	list_t *node = info->env;

	if (!node || !a)
		return (0);

	while (node)
	{
		ptr = init(node->str, a);
		if (ptr && *ptr == '=')
		{
			info->env_changed = remove_node(&(info->env), c);
			c = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		++c;
	}
	return (info->env_changed);
}

/**
 * get_environ - Entry point
 * @info: parameter struct that contains arguments.
 *
 * Description:functions that returns the array copy of the environ.
 * Return: Always 0 (On Success)
 */
char **get_environ(infos_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_str(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}
