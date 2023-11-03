#include "main.h"

/**
 * sfree - Entry point
 * @str: string to be free.
 *
 * Description: function that frees up a string of a string.
 * Return: nothing.
 */
void sfree(char **str)
{
	char **c = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(c);
}

/**
 * buffree - Entry point
 * @ptr: address of pointer to be free.
 *
 * Description: frees the pointer and makes the address NULL.
 * Return: 1 if freed (On success), 0 if not.
 */
int buffree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
