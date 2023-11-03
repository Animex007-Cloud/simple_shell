#include "main.h"

/**
 * _strdup - Entry point
 * @str: string to be copied.
 *
 * Description: returns a pointer to a new allocated space.
 * Return: pointer to an array or NULL.
 */
char *_strdup(const char *str)
{
	char *s;
	int a = 0;

	if (str == NULL)
		return (NULL);

	while (*str++)
		++a;
	s = malloc(sizeof(char) * (a + 1));
	if (!s)
		return (NULL);
	for (++a; --a;)
		s[a] = *str--;
	return (s);
}

/**
 * _puts - Entry point
 * @str: string to print.
 *
 * Description: prints a string, followed by a new line.
 * Return: Nothing.
 */
void _puts(char *str)
{
	while (*str != '\0')
		_putchar(*str++);

	_putchar('\n');
}

/**
 * _strchr - Entry point
 * @s: the string
 * @c: the character
 *
 * Description: locates a character in a string.
 * Return: a pointer to the character.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*++s != '\0');

	return (NULL);
}

/**
 * _strncat - Entry point
 *
 * @dest: string to be appended to.
 * @src: string to append.
 * @n: append n number of bytes.
 *
 * Description: concatenate two strings together.
 * Return: concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b = 0;

	while (dest[a] != '\0')
		++a;

	while (src[b] != src[n])
	{
		dest[a] = src[n];
		++a;
		++b;
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - Entry point
 * @s1: first string.
 * @s2: second string
 *
 * Description: compare two strings.
 * Return: int telling the number of spaces between the two strings.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
