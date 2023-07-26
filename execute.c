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
	char *command = NULL;

	if (av[0] == NULL || av[0][0] == '\0')
		return (-1);
	if (strcmp(av[0], "exit") == 0)
		return (exit_cmd(av));
	else if (av)
	{
		command = get_path(av[0]);

		pid = fork();
		if (pid == 0)
		{

			if (execve(command, av, environ) == -1)
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
	return (0);
}
