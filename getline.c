#include "shell.h"

/**
 * get_line - get user argument on stdin
 *
 * Return: Pointer to user argument
 */
char *get_line(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t charsread;

	charsread = getline(&lineptr, &n, stdin);
	if (charsread  == -1)
	{
		if (feof(stdin))
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(lineptr);
			perror("getline error");
			exit(EXIT_FAILURE);
		}
		if (charsread == 1)
		{
			free(lineptr);
			return (NULL);
		}
	}
	if (lineptr[charsread - 1] == '\n')
		lineptr[charsread - 1] = '\0';

	return (lineptr);
}
