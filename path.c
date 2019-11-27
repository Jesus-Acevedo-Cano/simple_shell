#include "header.h"
/**
 * path - function to get the path and concat with the input command
 * @tokens: pointer to pointer
 * @env: environment
 *
 * Return: void
 */
void path(char **tokens, char **env)
{
	char *find, *fakepath;
	int counter = 0, i, j;
	struct stat sts;

	find = strtok(env[counter], "=");

	while (env[counter] != NULL)
	{
		if (_strcmp(find, "PATH") == 0)
		{
			find = strtok(NULL, "\n");
			break;
		}
		counter++;
		find = strtok(env[counter], "=");
	}
	if (find != NULL)
	{
		find = strtok(find, ":");
		while (find != NULL)
		{
			for (i = 0; tokens[0][i] != '\0'; i++)
				;
			for (j = 0; find[j] != '\0'; j++)
				;
			fakepath = malloc(sizeof(char) * (i + j + 2));
			if (fakepath == NULL)
				perror("Error");
			_strcpy(fakepath, find);
			_strcat(fakepath, "/");
			_strcat(fakepath, tokens[0]);
			fakepath[i + j + 1] = '\0';
			if (stat(fakepath, &sts) == 0)
			{
				exec(fakepath, tokens, env);
			}
			free(fakepath);
			find = strtok(NULL, ":");
		}
	}
}

/**
 * exec - function to execute the commands
 * @fakepath: pointer to char
 * @tokens: pointer to pointer
 * @env: environment
 *
 * Return: integer
 *
 */
int exec(char *fakepath, char **tokens, char **env)
{
	int execute;

	execute = execve(fakepath, tokens, env);

	if (execute == -1)
	{
		perror("Execve error");
		free(fakepath);
	}
	free(fakepath);
	exit(0);
}
