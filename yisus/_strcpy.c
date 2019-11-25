#include "header.h"
/**
 * _strcpy - function that copies the string pointed to by src
 * @dest: array elements
 * @src: array elements
 *
 * Return: is a void
 */

char *_strcpy(char *dest, char *src)
{
	int count;

	count = 0;

	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
