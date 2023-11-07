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

/**
 * _memset - Entry point
 * @ptr: the pointer to the memory
 * @byte: the byte to fill the memory.
 * @num: the number of byte to fill in the memory.
 *
 * Description: fills the memory with constant byte.
 * Return: pointer to the memory filled.
 */
char *_memset(char *ptr, char byte, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; ++i)
		ptr[i] = byte;
	return (ptr);
}

/**
 * _realloc - Entry point
 * @ptr: pointer to recent allocated block of memory.
 * @old: bytes of recent memory block
 * @new: byte of new memory block
 *
 * Description: function that reallocate a block of memory.
 * Return: pointer.
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	char *c;

	if (!ptr)
		return (malloc(new));
	if (!new)
		return (free(ptr), NULL);
	if (new == old)
		return (ptr);

	c = malloc(new);
	if (!c)
		return (NULL);

	old = old < new ? old : new;
	while (--old)
		c[old] = ((char *)ptr)[old];
	free(ptr);
	return (c);
}
