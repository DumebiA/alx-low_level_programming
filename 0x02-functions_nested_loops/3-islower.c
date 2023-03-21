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
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
