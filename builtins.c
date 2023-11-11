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
			info->stats = 2;
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

/**
 * my_cd - Entry point
 * Description: Changes the current working directory.
 *
 * @info: Parameter that contains argument.
 * Return: Always 0 (on success)
 */

int my_cd(infos_t *info)
{
	char *a, *inv, buffer[1024];
	int chdir_ret;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		inv = get_env(info, "HOME=");
		if (!inv)
			chdir_ret = chdir((inv = get_env(info, "PWD=")) ? inv : "/");
		else
			chdir_ret = chdir(inv);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!get_env(info, "OLDPWD="))
		{
			_puts(a);
			_putchar('\n');
			return (1);
		}
		_puts(get_env(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((inv = get_env(info, "OLDPWD=")) ? inv : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_err(info, "can't cd to ");
		_puts(info->argv[1]), _errputchar('\n');
	}
	else
	{
		set_env(info, "OLDPWD", get_env(info, "PWD="));
		set_env(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * shell_help - Entry point
 * Description: get help information when command is triggered.
 *
 * @info: Contains argument used to fetch help.
 * Return: Always 0 (on success)
 */

int shell_help(infos_t *info)
{
	char **a;

	a = info->argv;
	_puts("help call works. Function not implemented yet \n");
	if (0)
		_puts(*a);
	return (0);
}
