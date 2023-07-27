#include "shell.h"

/**
 * builtins - check if command is a builtin or a process
 * @av: command and its flags
 *
 * Return: 1 on sucess
 */
int builtins(char **av)
{
	unsigned long int i;

	char *builtin_list[] = {
		"env",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		&env_cmd,
		&exit_cmd
	};

	i = 0;

	if (av[0] == NULL)
	{
		return (-1);
	}

	for (; i < sizeof(builtin_list) / sizeof(char *); i++)
	{
		if (strcmp(av[0], builtin_list[i]) == 0)
		{
			return ((*builtin_func[i])(av));
		}
	}
	return (execute(av));
}
