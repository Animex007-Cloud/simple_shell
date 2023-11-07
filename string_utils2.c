#include "main.h"

/**
 * _strlen - Entry point
 * @str: string which length is to be checked.
 *
 * Description: function to check the length of a string.
 * Return: return the number of string checked,
 * return 0 if string is NULL.
 */
int _strlen(char *str)
{
	int a = 0;

	if (!str)
		return (0);

	while (*++str)
		++a;
	return (a);
}

/**
 * _strcat - Entry point
 * @dest: the destination of the buffer to append.
 * @src: the source of the buffer.
 *
 * Description: function that concatenates two strings together.
 * Return: pointer to dest of the buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *c = dest;

	while (*dest)
		++dest;
	while (*src)
		*++dest = *++src;
	*dest = *src;
	return (c);
}

/**
 * init - Entry point
 * @str: string to be searched.
 * @sub: the substring to locate.
 *
 * Description: checks if sub starts with string.
 * Return: address of next character in str or NULL if not found.
 */
char *init(const char *str, const char *sub)
{
	while (*sub)
		if (*++sub != *++str)
			return (NULL);
	return ((char *)str);
}
