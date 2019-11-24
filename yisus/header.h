#ifndef OURLUB_H
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
/*prototype functions*/
int promp(int ac, char *av[], char *envp[]);
#endif
