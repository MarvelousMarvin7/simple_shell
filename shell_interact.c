#include "shell.h"

/**
 * shell_interact - Interpret command line
 *
 * Return: Nothing
 */
void shell_interact(void)
{
	char *lineptr;
	char **av;
	int status = -1;

	do {
		write(1, "#cisfun$ ", 9);
		fflush(stdout);
		lineptr = get_line();
		if (strlen(lineptr) == 0)
		{
			free(lineptr);
			continue;
		}
		av = token(lineptr);
		status = builtins(av);

		free(lineptr);
		free(av);
		if (status >= 0)
			exit(status);
	} while (status == -1);

}
