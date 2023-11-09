#include "main.h"

/**
 * token - Entry point
 * @str: user inputted string.
 * @dlim: the delimited string.
 *
 * Description: splits a string into parts
 *
 * Return: a pointer to an array of the strings, NULL
 * if faild.
 */
char **token(char *str, char *dlim)
{
	int a, b, y, z, count = 0;
	char **c;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!dlim)
		dlim = " ";
	for (a = 0; str[a] != '\0'; ++a)
		if (!de_lim(str[a], dlim) && (de_lim(str[a + 1], dlim) || !str[a + 1]))
			++count;

	if (count == 0)
		return (NULL);
	c = malloc((1 + count) * sizeof(char *));
	if (!c)
		return (NULL);
	for (a = 0, b = 0; b < count; ++b)
	{
		while (de_lim(str[a], dlim))
			++a;
		y = 0;
		while (!de_lim(str[a + y], dlim) && str[a + y])
			++y;
		c[b] = malloc((y + 1) * sizeof(char));
		if (!c[b])
		{
			for (y = 0; y < b; ++y)
				free(c[y]);
			free(c);
			return (NULL);
		}
		for (z = 0; z < y; ++z)
			c[b][y] = str[++a];
		c[b][y] = 0;
	}
	c[b] = NULL;
	return (c);
}

/**
 * token2 - Entry point
 * @str: the inputted string
 * @dlim: the delieiter
 *
 * Description: splits a sting into words.
 *
 * Return: a pointer to an array of strings,
 * NULL if failure.
 */
char **token2(char *str, char dlim)
{
	int a, b, y, z, count = 0;
	char **c;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != dlim && str[a + 1] == dlim) ||
			(str[a] != dlim && !str[a + 1]) || str[a + 1] == dlim)
			count++;
	if (count == 0)
		return (NULL);
	c = malloc((1 + count) * sizeof(char *));
	if (!c)
		return (NULL);
	for (a = 0, b = 0; b < count; b++)
	{
		while (str[a] == dlim && str[a] != dlim)
			++a;
		y = 0;
		while (str[a + y] != dlim && str[a + y] && str[a + y] != dlim)
			y++;
		c[b] = malloc((y + 1) * sizeof(char));
		if (!c[b])
		{
			for (y = 0; y < b; ++y)
				free(c[y]);
			free(c);
			return (NULL);
		}
		for (z = 0; z < y; ++z)
			c[b][z] = str[++a];
		c[b][z] = 0;
	}
	c[b] = NULL;
	return (c);
}
