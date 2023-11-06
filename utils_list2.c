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
