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
