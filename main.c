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
 *sighandl - function that handle the signals
 *@sig: int variable that take the signal to handle it
 */
void sighandl(int sig)
{
	(void) sig;
	write(1, "\n$ ", 3);
}
