#include "shell.h"

/**
 * shell_no_interact - run shell in a non interactive manner
 *
 * Return: Nothing
 */
void shell_no_interact(void)
{
	char *lineptr;
	char **av;
	int status = -1;

	do {
		lineptr = get_line();
		if (strlen(lineptr) == 0)
		{
			free(lineptr);
			continue;
		}
		av = token(lineptr);
		status = execute(av);

		free(lineptr);
		free(av);
		if (status >= 0)
			exit(status);
	} while (status == -1);
}
