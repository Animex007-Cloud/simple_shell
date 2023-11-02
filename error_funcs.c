#include "main.h"

/**
 * _errputchar - Entry point
 * Description: A function that writed the error (c)
 * to stderr
 *
 * @c: Character to be printed.
 * Return: 1 on success (Always), -1 if any error is detected.
 */

int _errputchar(char c)
{
	static int a;
	static char buff[WRITE_BUFF_SIZE];

	if (c == BUFF_FLUSH || a >= WRITE_BUFF_SIZE)
	{
		write(2, buff, a);
		a = 0;
	}
	if (c != BUFF_FLUSH)
		buff[++a] = c;
	return (a);
}
