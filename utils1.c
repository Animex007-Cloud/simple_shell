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

/**
 * is_chain - Entry point
 * @info: the struct list
 * @buff: the char's buffer
 * @a: address of current entity in buffer.
 *
 * Description: check if current char in the buffer is a chain delimeter
 * Return: 1 on Success, 0 if failed.
 */
int is_chain(infos_t *info, char *buff, size_t *a)
{
	size_t i = *a;

	if (buff[i] == '|' && buff[i + 1] == '|')
	{
		buff[i] = 0;
		++i;
		info->cmd_buff_type = CMD_OR;
	}
	else if (buff[i] == '&' && buff[i + 1] == '&')
	{
		buff[i] = 0;
		info->cmd_buff_type = CMD_CHAIN;
	}
	else
		return (0);
	*a = i;
	return (1);
}

/**
 * if_chain - Entry point
 * @info: struct lisy
 * @buff: the cha's buffer
 * @a: address of current position of entity in the buffer.
 * @i: initial position in the buffer.
 * @len: length of the buffer.
 *
 * Description: checks if chaining should continue based on is_chain.
 *
 * Return: nothing.
 */
void if_chain(infos_t *info, char *buff, size_t *a, size_t i, size_t len)
{
	size_t b = *a;

	if (info->cmd_buff_type == CMD_AND)
	{
		if (info->status)
		{
			buff[i] = 0;
			b = len;
		}
		if (info->cmd_buff_type == CMD_OR)
		{
			if (!info->status)
			{
				buff[i] = 0;
				b = len;
			}
		}
	}
	*a = b;
}
