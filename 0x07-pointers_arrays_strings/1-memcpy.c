#include "main.h"

/**
 *_memcpy - function that copies memory area
 *@dest: memory stored
 *@src: memory copied
 *@n: no of bytes
 *
 *Return: memory with n byts
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int m = 0;
	int o = n;

	for (; m < o; m++)
	{
		dest[m] = src[m];
		n--;
	}
	return (dest);
}
