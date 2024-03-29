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
	char *buf = NULL, *tokens[32], *exit_ = "exit\n";
	size_t bufLen;
	int getl, sts;
	pid_t son;
	(void)av;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		getl = getline(&buf, &bufLen, stdin);
		if (_strcmp(buf, exit_) == 0)
		{
			free(buf);
			return (0);
		}
		if (getl == -1)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			free(buf);
			return (ac - ac);
		}
		if (getl > 1)
		{
			tok(buf, tokens);
			son = fork();
			if (son == -1)
				perror("fork");
			if (son == 0)
			{
				if (execve(tokens[0], tokens, envp) == -1)
					path(tokens, envp);
				free(buf), exit(0);
			}
			if (son > 0)
				wait(&sts);
		}
	}
	free(buf);
	return (0);
}
/**
 * tok - function to separate the commands
 * @buf: input commands
 * @tokens: separated tokens
 *
 * Return: tokens
 *
 */
char **tok(char *buf, char **tokens)
{
	char *tok;
	int count;

	tok = strtok(buf, " \t\n\r");
	for (count = 0; tok != NULL; count++)
	{
		tokens[count] = tok;
		tok = strtok(NULL, " \t\n\r");
	}
	tokens[count] = NULL;
	return (tokens);
}
