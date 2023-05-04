#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int decVal = 0;
	int n = 0;

	if (b == NULL)
		return (0);

	while (b[n] == '0' || b[n] == '1')
	{
		decVal <<= 1;
		decVal += b[n] - '0';
		n++;
	}
		return (decVal);
}
