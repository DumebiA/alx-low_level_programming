#include "main.h"

/**
 * _islower - main funct
 *
 * @c: checks parameter
 *
 * Return: 1 for alphabet
 * and 0 if not
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
