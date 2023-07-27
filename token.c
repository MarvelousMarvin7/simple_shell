#include "shell.h"

/**
 * token - splits user input into strings
 * @lineptr: user input to splits
 *
 * Return: Nothing
 */
char **token(char *lineptr)
{
	int bufsize = 10, i = 0;
	char *token;
	char **tokens;
	unsigned int newsize;

	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}
	token = _strtok(lineptr, DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			newsize = bufsize * sizeof(char *);
			tokens = _realloc(tokens, bufsize * sizeof(char *),
					  newsize);
			if (!tokens)
			{
				perror("reallocation failed");
				exit(EXIT_FAILURE);
			}
			bufsize = newsize / sizeof(char *);
		}
		token = _strtok(NULL, DELIM);
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * _realloc - realllocates memory
 * @ptr: pointer to old memory
 * @old_size: old size of ptr
 * @new_size: new size of new allocated space
 *
 * Return: Pointer to new memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *copy;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	copy = ptr;
	for (i = 0; i < old_size; i++)
		p[i] = copy[i];
	free(ptr);

	return (p);
}

/**
 * _strtok - tokenizes strings
 * @str: string
 * @delim: delimiter
 *
 * Return: token;
 */
char *_strtok(char *str, char *delim)
{
	char *token;
	static char *next_token;

	if (str == NULL)
		str = next_token;
	if (str == NULL || *str == '\0')
		return (NULL);
	while (*str != '\0' && _strchr(delim, *str) != NULL)
		str++;
	if (*str == '\0')
		return (NULL);
	token = str;

	while (*str != '\0' && _strchr(delim, *str) == NULL)
		str++;
	if (*str != '\0')
	{
		*str = '\0';
		next_token = str + 1;
	}
	else
		next_token = NULL;

	return (token);
}

/**
 * _strchr - fills memory with constant bytes
 * @s: pointer of characters
 * @c: characters to locate
 * Return: s else NULL
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	if (s[i] == c)
		return (s + i);
	return (0);
}
