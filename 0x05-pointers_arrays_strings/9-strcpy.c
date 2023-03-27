#include "main.h"

/**
 * char *_strcpy - function
 * @dest: to copy
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int o = 0;

	while (*(src + i) != '\0')
	{
		i++;
	}
	for ( ; o < i ; o++)
	{
		dest[o] = src[o];
	}
	dest[i] = '\0';
	return (dest);
}
