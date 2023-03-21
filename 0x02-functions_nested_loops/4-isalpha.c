#include "main.h"
/**
 * _isalpha - main function
 *
 * @c: to check c
 *
 * Return: returns to 1 if alpabet
 * and 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
