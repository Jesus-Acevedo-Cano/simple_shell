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
	int i = 0;

	signal(SIGINT, sighandl);

	if (ac > 1)
	{
		/*exec(ac, av, envp);*/
	}
	else
		i = promp(ac, av, envp);
	return (i);
}
/**
 *
 *
 *
 */
void sighandl(int sig) 
{
	signal(sig, SIG_IGN);
	signal(SIGINT, sighandl);
}
