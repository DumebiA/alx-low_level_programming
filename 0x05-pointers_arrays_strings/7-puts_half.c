#include "main.h"

/**
 * puts_half - a function prints half a string
 * if odd , b = (length of string - 1) / 2
 * @str: input
 * Return: half input
 */

void puts_half(char *str)
{
	int a, b, li;

	li = 0;

	for (a = 0; str[a] != '\0'; a++)
		li++;

	b = (li / 2);

	if ((li % 2) == 1)
		b = ((li + 1) / 2);

	for (a = b; str[a] != '\0'; a++)
		_putchar(str[a]);
	_putchar('\n');
}
