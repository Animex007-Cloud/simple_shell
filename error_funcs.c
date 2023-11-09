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

/**
 * print_err - Entry point
 * @info: from struct
 * @err: string with error.
 *
 * Description: prints error message on screen.
 * Return: 0 if string contains no numbers.
 */
void print_err(infos_t *info, char *err)
{
	_puts(info->file_name);
	_puts(": ");
	print_dec(info->err_count, STDERR_FILENO);
	_puts(": ");
	_puts(info->argv[0]);
	_puts(": ");
	_puts(err);
}

/**
 * print_dec - Entry point
 * @in: the input.
 * @fd: the file descriptor to write into.
 *
 * Description: function that prints integer in base 10.
 * Return: numbers of value printed.
 */
int print_dec(int in, int fd)
{
	int (*__putchar)(char) = _putchar;
	int a, add = 0;
	unsigned int p, position;

	if (fd == STDERR_FILENO)
		__putchar = _errputchar;
	if (in < 0)
	{
		p = -in;
		__putchar('-');
		++add;
	}
	else
		p = in;
	position = p;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (p / a)
		{
			__putchar('0' + position / a);
			++add;
		}
		position %= a;
	}
	__putchar('0' + position);
	++add;

	return (add);
}

/**
 * err_atoi - Entry point
 * @str: string to be converted
 * Description: prints an error when string is not converted.
 *
 * Return: 0 if no numbers are in string,
 * converted number if numbers are present in string (-1).
 */
int err_atoi(char *str)
{
	int a = 0;
	unsigned long int total = 0;

	if (*str == '+')
		++str;
	for (a = 0; str[a] != '\0'; ++a)
	{
		if (str[a] >= '0' && str[a] <= '9')
		{
			total *= 10;
			total += (str[a] - '0');
			if (total > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (total);
}

/**
 * converter - Entry point
 * @i: integer to convert
 * @base: the base to be converted to.
 * @flag: arguments
 *
 * Description: convert integer to character.
 * Return: a string when successful.
 */
char *converter(long int i, int base, int flag)
{
	static char *ptr;
	static char buffer[50];
	char sign = 0;
	char *c;
	unsigned long n = i;

	if (!(flag & CON_UNSIGNED) && i < 0)
	{
		n = -i;
		sign = '-';
	}
	ptr = flag & LOWERCASE ? "012345678abcdef" : "012345678ABCDEF";
	c = &buffer[49];
	c = '\0';

	do {
		*c-- = ptr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*c-- = sign;
	return (c);
}
