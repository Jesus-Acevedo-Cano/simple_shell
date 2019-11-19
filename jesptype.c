#include "header.h"

int main(void)
{
	char *ptr, *tok;
	int count = 0;
	size_t cont = 0;
	char* argv[] = { "/bin/ls", "-la", "/usr/", NULL };//argv[2] = path option
	char* envp[] = { NULL };

	while (1)
	{
		write(1, "$ ", 2);
		getline(&ptr, &cont, stdin);
		/*tok = strtok(ptr, " \n\t\r");*/
		//pruebas para ejecutar funciones
		//argv[0] = ptr?;// concat /bin/ + ptr(input)
		//fork();
		execve(argv[0], argv, envp);
		perror("Could not execve");
	}
	return (0);
}
