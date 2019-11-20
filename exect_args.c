#include "header.h"

int exect(char **args)
{
	pid_t pid, waitpd;
	int s;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("lpm");
		}
			exit(EXIT_FAILURE);
	} 
	else if (pid < 0)
	{
		perror("lpm2");
	}
	else
	{
		do
		{
		waitpd = waitpid(pid, &s, WUNTRACED);
		}
		while (!WIFEXITED(s) && !WIFSIGNALED(s));
	}
	return (1);
}
