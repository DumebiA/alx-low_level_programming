#include "main.h"
/**
 * print_rev - prime
 * @s: string
 * return: 0
 */
void print_rev(char *s)
{
	int li = 0;
	int i;

	while (*s != '\0')
	{
		li++;
		s++;
	}
	s--;
	for (i = li; i > 0; i--)
	{
		_putchar(*s);
		s--;
	}

	_putchar('\n');
}
