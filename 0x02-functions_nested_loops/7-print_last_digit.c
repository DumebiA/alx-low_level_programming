#include "main.h"
/**
 * print_last_digit - Main function
 *
 * @n: acts as integar
 *
 * Return: return to value of i
 */

int print_last_digit(int n)
{
	int i;

	if (n < 0)
		n = -n;

	i = n % 10;

	if (i < 0)
		i = -i;

	_putchar(i + '0');

	return (i);

}
