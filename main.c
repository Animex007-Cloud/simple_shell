#include "main.h"

/**
 * main - Entry point
 * @ac: args count
 * @av: args vector
 *
 * Description: main file to make the shell execute.
 * Return: 0 on success (Always), 1 if an error encountered.
 */
int main(int ac, char **av)
{
	infos_t info[] = { INFO_INIT };
	int fd = 2;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_errputs(av[0]);
				_errputs(": 0: Can't open ");
				_errputs(av[1]);
				_errputchar(BUFF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->read_fd = fd;
	}
	env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
