#include "header.h"
/**
 * main - main function
 * @ac: arguments counter
 * @av: arguments array
 * @envp: environment
 *
 * Return: integer
 *
 */
int main(int ac, char *av[], char *envp[])
{
	if (ac > 1)
	{
		/*exec(ac, av, envp);*/
	}
	else
		promp(ac, av, envp);
	return (0);
}
