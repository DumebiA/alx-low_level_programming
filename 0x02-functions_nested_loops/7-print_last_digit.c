#include "main.h"
/**
 * print_last_digit - Main function
 *
 * @m: acts as integar
 *
 * Return: return to n
 */

int print_last_digit(int r)
{
	int n;

	n = r % 10;
	if (r < 0)
		n = -n;
	return (n);
}
