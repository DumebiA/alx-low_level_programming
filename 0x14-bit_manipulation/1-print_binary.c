#include <stdio.h>
#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */

void print_binary(unsigned long int n)
{
	int m;
	int sum = 0;
	unsigned long int pres;

	for (m = 63; m >= 0; m--)
	{
		pres = n >> m;

		if (pres & 1)
		{
			_putchar('1');
			sum++;
		}
		else if (sum)
			_putchar('0');
	}
	if (!sum)
		_putchar('0');
}
