#include "shell.h"

/**
 * main - Main shell program
 *
 * Return: Always 0
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interact();
	}
	else
	{
		shell_no_interact();
	}
	return (0);
}
