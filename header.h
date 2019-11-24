#ifndef OURLUB_H
#define OURLIB_H
/*libraries*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*prototype functions*/
int rdl(int ac, char *av[], char *envp[]);
int exect(char **args, char *envp[]);
#endif
