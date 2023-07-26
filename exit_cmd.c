#include "shell.h"

/**
 * exit_cmd - built-in command to exit the shell.
 * @av: The argument vector
 *
 * Return: The exit status to be used when terminating the shell.
 */
int exit_cmd(char **av)
{
	(void) av;

	exit(0);
}
