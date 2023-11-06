#include "main.h"

/**
 * _putchar - writes the character c to stdout.
 * @c: The character to print.
 *
 * Return: 1 on success.
 * on error -1 is returned and errno is set appropriately.
 */

int _putchar(char c)
{
	static int a;
	static char buff[WRITE_BUFF_SIZE];

	if (c == BUFF_FLUSH || a >= WRITE_BUFF_SIZE)
	{
		write(1, buff, a);
		a = 0;
	}
	if (c != BUFF_FLUSH)
		buff[++a] = c;
	return (a);
}
