#include "main.h"

/**
 * print_numbers - checks for checks for a digit 0 through 9
 * Return: always 0
 */

void print_numbers(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
	_putchar(n + '0');
	}
	_putchar('\n');
}
