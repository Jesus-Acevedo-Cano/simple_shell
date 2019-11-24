#include "header.h"
int main(int ac, char *av[], char *envp[])
{
	if (ac > 1)
	{
	}
	else
	{
		rtl(ac, av, envp);
	}

	return (0);
}

int rtl(int ac, char *av[], char *envp[])
{
	char *line, *tok;
	int c = 0;
	size_t buf = 0;

	while (1)
	{
		write(1, "$ ", 2);
		if (getline(&line, &buf, stdin) == -1)
		{
			write(1, "\n", 1);
			exit(0);
		}
		tok = strtok(line, " \n\t");
		while (tok != NULL)
		{
			av[c] = tok;
			tok = strtok(NULL, " \n\t");
			c++;
		}
		av[c] = NULL;
		exect(av, envp);
	}
	return (EXIT_SUCCESS);
}

int exect(char **args, char *envp[])
{
	pid_t pid;
	int sts;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
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
		wait(&sts);
	}
	return (0);
}
