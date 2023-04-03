#include "main.h"

/**
 * _memset - block of memory with a value
 * @s: memory address
 * @b: the value
 * @n: no of bytes changed
 *
 * Return: changed array with new value for n bytes
 */

char *_memset(char *s, char b, unsigned int n)
{
	int m = 0;

	for (; n > 0; m++)
	{
		s[m] = b;
		n--;
	}
	return (s);
}
