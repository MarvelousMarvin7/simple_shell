#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

#define DELIM " \t\n\r\a"

void shell_interact(void);
void shell_no_interact(void);

char *get_line(void);
char **token(char *lineptr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int execute(char **av);
char *get_path(char *command);
int exit_cmd(char **av);
int _atoi(const char *str);
int env_cmd(char **av);
int builtins(char **av);

#endif /*SHELL_H*/
