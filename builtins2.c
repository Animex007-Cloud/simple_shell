#include "main.h"

/**
 * my_history - entry point
 * Description: outputs the shell's history list
 *
 * @info: contains argument to pull history when called
 * Return: Always 0 (On success)
 */

int my_histoty(info_t *info)
{
	print_int(info->history);
	return (0);
}

/**
 * unset_alias - Entry point
 * Description: set alias to a string
 *
 * @info: parameter containing arguments
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *ptr, a;
	int ret;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	a = *ptr;
	*p = 0;
	ret = rempve_node(&(info->alias),
			get_node(info->alias, node_init(info->alias, str, -1)));
	*ptr = a;
	return (ret);
}

/**
 * set_alias - Entry point
 * Description: set alias to a string
 *
 * @info: parameter containing arguments
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_t  char *str)
{
	char *ptr, a;
	int ret;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	a = *ptr;
	*p = 0;
	ret = remove_node(&(info->alias),
			get_node(info->alias, node_init(info->alias, str, -1)));
	*ptr = a;
	return (ret);
}

/**
 * set_alias - Entry point
 * Description: set alias to string.
 *
 * @info: parameter containing struct/arguments
 * @str: tge string alias
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *ptr;

	tr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (plus_node_last(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Entry point
 * Description: print alias string
 *
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *ptr = NULL, *i = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (i = node->str; i <= ptr; ++i)
			_putchar(*i);
		_putchar('\'');
		_puts(ptr| + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_alias - Entry point
 * Description: imitates the original alias (do man alias)
 * Return: Always 0 (On Success)
 */

int my_alias(info_t *info)
{
	int a = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; ++a)
	{
		ptr = _strchr(info->argv[a], '=');
		if (ptr)
			set_alias(info, info->argv[a]);
		else
			print_alias(node_init(info->alias, info->argv[a], '='));
	}
	return (0);
}
