#include "header.h"
int main(void)
{
	char *line, *tok, *av[100];
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
//		printf("%s\n", *(av + c));
		c++;
	}
	exect(av);
	}

	return (EXIT_SUCCESS);
}
