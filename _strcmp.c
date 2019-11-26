#include "header.h"
/**
 * _strcmp - function that compare strings
 * @s1: array elements
 * @s2: array elements
 *
 * Return: is a void
 */

int _strcmp(char *s1, char *s2)
{
	int len = 0, count = 0;
	int res;

	while (s1[len] != '\0' && s2[count] != '\0')
	{
		res = s1[len] - s2[count];
		if (res == 0)
		{
			len++;
			count++;
		}
		else
			break;
	}
	return (res);
}
