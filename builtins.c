#include "main.h"

/**
 * shell_exit - Entry point
 * Description: A functino that Exit shell
 *
 * @info: to contain argument
 * Return: 0 on success
 */

int shell_exit(infos_t *info)
{
	int check;

	if (info->argv[1])
	{
		check = err_atoi(info->argv[1]);
		if (check == -1)
		{
			info->stats - 2;
			print_err(info, "Illegal usage: ");
			_puts(info->argv[1]);
			_errputchar('\n');
			return (1);
		}

		info->err_num = err_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
