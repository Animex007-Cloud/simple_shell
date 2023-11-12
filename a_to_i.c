#include "main.h"

/**
 * interactive - Entry point
 * @info: struct address (pointer)
 *
 * Description: returns result if shell is interactive
 * Return: 1 if on interactive mode, 0 if failure occurs.
 */
int interactive(infos_t *info)
{
	return (isatty(STDIN_FILENO) && info->read_fd <= 2);
}

/**
 * _isalpha - Entry point
 * @i: the character to be inputted.
 *
 * Description: checks if character is an alphabet.
 * Return: 1 if i is an alphabet, ) if not.
 */
int _isalpha(int i)
{
	if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Entry point
 * @str: the sting to be converted.
 *
 * Description: converts a string to an integer.
 *
 * Return: 0 if no numbers are in the string,
 * return converted number on success
 */
int _atoi(char *str)
{
	unsigned int output = 0;
	int a, sign = 1, flag = 0, result;

	for (a = 0; str[a] != '\0' && flag != 2; ++a)
	{
		if (str[a] == '-')
			sign *= -1;

		if (str[a] >= '0' && str[a] <= '9')
		{
			flag = 1;
			output *= 10;
			output += (str[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		result = -output;
	else
		result = output;
	return (result);
}

/**
 * _errputs - Entry point
 * @str: the error string to be printed.
 * Description: prints an inputted string (error).
 *
 * Return: Nothing.
 */
void _errputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_errputchar(str[a]);
		++a;
	}
}
