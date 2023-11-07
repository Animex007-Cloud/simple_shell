#include "main.h"

/**
 * free_list - Entry point
 * Description: A function that frees the list (all nodes)
 * @ptr: pointer to head of the node to be freed.
 * Return: nothing
 */

void free_list(list_t **ptr)
{
	list_t *node, *next_node, *top;

	if (!ptr || *ptr)
		return;
	top = *ptr;
	node = top;

	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*ptr = NULL;
}

/**
 * plus_node - Entry point
 * @head: address of pointer to the head node(begin)
 * @str: string of node.
 * @i: node index utilized by history.
 *
 * Description: include node to the start of the list.
 * Return: size of the list or NULL if failed.
 */
list_t *plus_node(list_t **head, const char *str, int i)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->i = i;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * plus_node_last - Entry point
 * @head: address of pointer to the head node(begin)
 * @str: string of node
 * @i: node index utilized by history.
 *
 * Description: includes node to the end of the list.
 * Return: size of the list, otherwise NULL
 */
list_t *plus_node_last(list_t **head, const char *str, int i)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);
	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->i = i;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * remove_node - Entry point
 * @head: address of pointer to the initial node.
 * @index: location of node to delete.
 *
 * Description: removes a node at a specific index.
 * Return: 1 (On success), otherwise 0 if failure occur.
 */
int remove_node(list_t **head, unsigned int index)
{
	list_t *node, *past_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;

	while (node)
	{
		if (i == index)
		{
			past_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		++i;
		past_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * print_list_str - Entry point
 * @ptr: pointer of the first node.
 *
 * Description: prints str of list_t list.
 * Return: size of the list.
 */
size_t print_list_str(const list_t *ptr)
{
	size_t i = 0;

	while (ptr)
	{
		_puts(ptr->str ? ptr->str : "(nil)");
		_puts("\n");
		ptr = ptr->next;
		++i;
	}
	return (i);
}
