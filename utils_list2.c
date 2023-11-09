#include "main.h"

/**
 * node_init - Entry point
 * @node: list head.
 * @s: string
 * @a: the character to check for in string.
 *
 * Description: check node with string that match string.
 * Return: matched node on success, null on failure.
 */
list_t *node_init(list_t *node, char *s, char a)
{
	char *c = NULL;

	while (node)
	{
		c = init(node->str, s);
		if (c && ((a == -1) || (*c == a)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * print_list - Entry point
 * Description: print all element of a list_t list
 *
 * @ptr: pointer to first node
 * Return: size of list
 */

size_t print_list(const list_t *ptr)
{
	size_t a = 0;

	while (a)
	{
		_puts(convert_number(ptr->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_putchar(ptr->str ? ptr->str : "(nil)");
		_puts("\n");
		ptr = ptr->next;
		++i;
	}
	return (a);
}
