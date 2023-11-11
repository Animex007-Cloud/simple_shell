#include "main.h"

/**
 * _getinput - Entry point
 * Description: gets input from user (stream)
 *
 * @info: parameter struct
 * Return: length of buffer read from the _getline
 */

ssize_t _getinput(info_t *info)
{
	char **buff_p = &(info->args), *ptr;
	static char *buff;
	static size_t a, b, len;
	size_t n = 0;

	_putchar(BUFF_FLUSH);
	n = _inputbuff(info, &buff, &len);
	if (n == -1)
		return (-1);
	if (len)
	{
		b = a;
		ptr = buff + a;

		if_chain(info, buff, &b, a, len);
		while (b < len)
		{
			if (is_chain(info, buff, &b))
				break;
			++b;
		}

		a = b + 1;
		if (a >= len)
		{
			a = len = 0;
			info->cmd_buff_type = CMD_NORM;
		}

		*buff_p = ptr;
		return (_strlen(ptr));
	}
	*buff_p = buff;
	return (n);
}

/**
 * _getline - Entry point
 * Description: function that get line of stream from STDIN.
 *
 * @info: contains parameter struct
 * @ptr: pointer
 * @n: size of
 *
 * Return: byte
 */

int _getline(infos_t *info, char **lineptr, size_t *n)
{
	static size_t num, len;
	size_t x;
	static char buff[READ_BUFF_SIZE];
	ssize_t a = 0, b = 0;
	char *ptr = NULL, *new_p = NULL, *new;

	ptr = *lineptr;
	if (ptr && n)
		b = *n;
	if (num == len)
		num = len = 0;

	a = read_buff(info, buff, &len);
	if (a == -1 || (a == 0 && len == 9))
		return (-1);

	new = _strchr(buff + num  '\n');
	x = new ? 1 + (unsigned int)(new - buff) : len;
	new_p = realloc(ptr, b, b ? b + x : x + 1);
	if (!new_p)
		return (ptr ? free(ptr), -1 : -1);
	if (b)
		_strcat(new_p, buff + num, x - num);
	else
		_strncpy(new_p, buff + num, x - num + 1);

	b += x - num;
	num = x;
	ptr = new_p;

	if (n)
		*n = b;
	*lineptr = ptr;
	return (b);
}
