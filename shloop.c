#include "main.h"

/**
 * hsh - Entry point
 * @info: the parameter that contains argumenet.
 * @av: the argument vector gotten from main.c
 *
 * Description: function that handles shell loop
 * Return: Always 0 (On Success), 1 if an error is encountered.
 */
int hsh(infos_t *info, char **av)
{
	ssize_t a = 0;
	int builtins_ret = 0;

	while (a != -1 && builtins_ret != -2)
	{
		clear_infos(info);
		if (interactive(info))
			_puts("$ ");
		_errputchar(BUFF_FLUSH);
		a = _getinput(info);
		if (a != -1)
		{
			set_infos(info, av);
			builtins_ret = s_builtins(info);
			if (builtins_ret == -1)
				s_cmd(info); /*search cmd*/
		}
		else if (interactive(info))
			_putchar('\n');
		free_infos(info, 0);
	}
	write_history(info);
	free_infos(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtins_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}

	return (builtins_ret);
}

/**
 * fork_cmd - Entry point
 * @info: the parameter.
 *
 * Description: fork an exec to run cmd.
 * Return: nothing.
 */
void fork_cmd(infos_t *info)
{
	pid_t ppid;

	ppid = fork();
	if (ppid == -1)
	{
		perror("Error:");
		return;
	}
	if (ppid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_infos(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_err(info, "Permission denied\n");
		}
	}
}

/**
 * s_builtins - Entry point
 * @info: the parameter
 *
 * Description: function that search for a built_in command.
 * Return: -1 if builtins was not found
 * 0 if builtin was executed
 * 1 if builtin wasfound but not executed on success
 * -2 if builtin signal exited.
 */
int s_builtins(infos_t *info)
{
	int a, builtin_ret = -1;
	builtins_t builtins[] = {
		{"exit", shell_exit},
		{"env", my_env},
		{"help", shell_help},
		{"history", my_history},
		{"setenv", my_setenv},
		{"unsetenv", my_unsetenv},
		{"cd", my_cd},
		{"alias", my_alias},
		{NULL, NULL}
	};

	for (a = 0; builtins[a].flag; ++a)
		if (_strcmp(info->argv[0], builtins[a].flag) == 0)
		{
			info->err_count++;
			builtin_ret = builtins[a].func(info);
			break;
		}
	return (builtin_ret);
}

/**
 * s_cmd - Entry point
 * @info: the paramter that contatins argument.
 *
 * Description: search for commain in PATH
 * Return: nothing.
 */
void s_cmd(infos_t *info)
{
	char *path = NULL;
	int a, b;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->err_count++;
		info->linecount_flag = 0;
	}
	for (a = 0, b = 0; info->args[a]; a++)
		if (!de_lim(info->args[a], " \t\n"))
			++b;
	if (!b)
		return;

	path = f_path(info, get_env(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || get_env(info, "PATH=")
			|| info->argv[0][0] == '/') && _iscmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->args) != '\n')
		{
			info->status = 127;
			print_err(info, "not found\n");
		}
	}
}
