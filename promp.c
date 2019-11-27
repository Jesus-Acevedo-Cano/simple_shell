#include "header.h"
/**
 * promp - function to get the commands
 * @ac: arguments counter
 * @av: arguments array
 * @envp: environment
 *
 * Return: integer
 *
 */
int promp(int ac, char *av[], char *envp[])
{
	char *buf = NULL, *tok, *tokens[32], *exit_ = "exit\n";
	size_t bufLen;
	int getl, count = 0, exec, sts;
	pid_t son;
	(void)ac;
	(void)av;
	while (1)
	{
		write(1, "$ ", 2);
		getl = getline(&buf, &bufLen, stdin);
		if (_strcmp(buf, exit_) == 0)
			exit(0);
		if (getl == -1)
		{
			perror("getline"), exit(0);
		}
		if (getl > 1)
		{
			tok = strtok(buf, " \t\n\r");
			for (count = 0; tok != NULL; count++)
			{
				tokens[count] = tok;
				tok = strtok(NULL, " \t\n\r");
			}
			tokens[count] = NULL;
			son = fork();
			if (son == -1)
				perror("fork");
			if (son == 0)
			{
				exec = execve(tokens[0], tokens, envp);
				if (exec == -1)
					path(tokens, envp);
				exit(0);
			}
			if (son > 0)
				wait(&sts);
		}
	}
	return (0);
}
