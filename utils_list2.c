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
		_puts(converter(ptr->i, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(ptr->str ? ptr->str : "(nil)");
		_puts("\n");
		ptr = ptr->next;
		++a;
	}
	return (a);
}

/**
 * get_node - Entry point
 * @head: pointer to the list head.
 * @node: pointer to the current node.
 *
 * Description: function that gets the beginning of a node.
 * Return: index of the node, -1 on failure.
 */
ssize_t get_node(list_t *head, list_t *node)
{
	size_t a = 0;

	while (head)
	{
		if (head == node)
			return (a);
		head = head->next;
		++a;
	}
	return (-1);
}

/**
 * list_str - Entry point
 * @head: pointer to the first node.
 *
 * Description: returns an array of strings from the list_t (str)
 * Return: an array of strings.
 */
char **list_str(list_t *head)
{
	list_t *node = head;
	size_t a = list_len(head), b;
	char *s;
	char **str;

	if (!head || !a)
		return (NULL);
	str = malloc(sizeof(char *) * (a + 1));
	if (!str)
		return (NULL);
	for (a = 0; node; node = node->next, ++a)
	{
		s = malloc(_strlen(node->str) + 1);
		if (!s)
		{
			for (b = 0; b < a; ++b)
				free(str[b]);
			free(str);
			return (NULL);
		}
		s = _strcpy(s, node->str);
		str[a] = s;
	}
	str[a] = NULL;
	return (str);
}

/**
 * list_len - Entry point
 * @ptr: pointer to the first node.
 *
 * Description: function that determines the length of the linked list.
 * Return: size of the linked list.
 */
size_t list_len(const list_t *ptr)
{
	size_t a = 0;

	while (ptr)
	{
		ptr = ptr->next;
		++a;
	}
	return (a);
}
