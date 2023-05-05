#include <stdio.h>
#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int o;
	int p = 0;
	unsigned long int pres;
	unsigned long int ex = n ^ m;

	for (o = 63; o >= 0; o--)
	{
		pres = ex >> o;
		if (pres & 1)
			p++;
	}

	return (p);
}
