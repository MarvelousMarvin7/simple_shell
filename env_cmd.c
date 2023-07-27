#include "shell.h"

/**
 * own_env - function that prints enviroment variables
 * @av: arguments by user
 *
 * Return: 1 on success
 */
int env_cmd(char **av)
{     	int i = 0;

	(void)av;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}
