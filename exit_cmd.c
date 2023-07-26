#include "shell.h"
#include <limits.h>
#include <ctype.h>

/**
 * _atoi - convert string to integer
 * @str: string to convert
 *
 * Return: integer
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; ++i)
	{
		if (isdigit(str[i]))
			result = result * 10 + (str[i] - '0');
		else
			break;
	}

	return (result * sign);
}

/**
 * exit_cmd - built-in command to exit the shell.
 * @av: The argument vector
 *
 * Return: The exit status to be used when terminating the shell.
 */
int exit_cmd(char **av)
{
	if (av[1])
	{
		return (_atoi(av[1]));
	}
	else
	{
		return (0);
	}

}
