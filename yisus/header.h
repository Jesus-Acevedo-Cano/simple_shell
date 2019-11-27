#ifndef OURLIB_H
#define OURLIB_H

/*libraries*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/*declared functions*/
int promp(int ac, char *av[], char *envp[]);
int _strcmp(char *s1, char *s2);
void path(char **tokens, char **env);
int exec(char *fakepath, char **tokens, char **env);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
