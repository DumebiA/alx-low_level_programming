#include "main.h"
/**
 * _strncat - concatenate two string
 * using at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int o;
	int m;

	o = 0;
	while (dest[o] != '\0')
	{
		o++;
	}
	m = 0;
	while (m < n && src[m] != '\0')
	{
	dest[o] = src[m];
	o++;
	m++;
	}
	dest[o] = '\0';
	return (dest);
}
