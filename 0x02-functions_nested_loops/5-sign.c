#include "main.h"
/**
 * print_sign - main function
 *
 * @n: input number
 *
 * Return: 1 is greater than 0. 0 is 0
 * -1 is less than 0.
 */

int print_sign(int n)
{
	if (n > 0)
	{
		printf("+, ");
		return (1);
	}
	else if (n == 0)
	{
		printf("0, ");
		return (0);
	}
	else
	{
		printf("-, ");
		return (-1);
	}
}
