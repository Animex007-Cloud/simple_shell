#include "main.h"

/**
 * de_lim - Entry point
 * @c: the string to check.
 * @dlim: the delimeter string
 *
 * Description: checks if character is a delimeter.
 * Return: 1 if success, 0 if not a demimeter.
 */
int de_lim(char c, char *dlim)
{
	while (*dlim)
		if (*dlim++ == c)
			return (1);
	return (0);
}
