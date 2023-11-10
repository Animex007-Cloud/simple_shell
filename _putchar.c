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

/**
 * _fdput - Entry point
 * @a: the character to be printed.
 * @fd: the file descriptor.
 *
 * Description: writes the character a to a given fd.
 * Return: 1 On sucess, -1 On error.
 */
int _fdput(char a, int fd)
{
	static int i;
	static char buff[WRITE_BUFF_SIZE];

	if (a == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
	{
		write(fd, buff, a);
		i = 0;
	}
	if (a != BUFF_FLUSH)
		buff[++i] = a;
	return (1);
}

/**
 * _fdputs - Entry point
 * @str: The string to be printed.
 * @fd: the file descriptor.
 *
 * Description: prints the inputted string.
 * Return: the number of chars inputted.
 */
int _fdputs(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _fdput(*++str, fd);
	}
	return (a);
}

/**
 * sigintHandler - blocks ctrl+c from working
 * @_signum: the signal number.
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int _signum)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFF_FLUSH);
}
