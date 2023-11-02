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
