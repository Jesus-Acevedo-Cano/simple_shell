#include "header.h"
/**
 * _strcat - function that concatenates strings
 * @dest: array elements
 * @src: array elements
 *
 * Return: is a void
 */

char *_strcat(char *dest, char *src)
{
	int len = 0, count = 0;

	while (dest[len] != '\0')
		len++;
	while (src[count] != '\0')
	{
		dest[len + count] = src[count];
		count++;
	}
	dest[len + count] = '\0';
	return (dest);
}
