#include "shell.h"

/**
 * execute - execute user input
 * @av: user input to execute
 *
 * Return: 1 if success
 * 0n error, return 0;
 */
int execute(char **av)
{
	pid_t pid;
	int status;

	if (av[0] == NULL || av[0][0] == '\0')
		return (-1);

	pid = fork();
	if (pid == 0)
	{

		if (execve(av[0], av, environ) == -1)
		{
			perror("./shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in child process: forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
