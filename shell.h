#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define DELIM " \t\n\r\a"

void shell_interact(void);

char *get_line(void);
char **token(char *lineptr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /*SHELL_H*/
