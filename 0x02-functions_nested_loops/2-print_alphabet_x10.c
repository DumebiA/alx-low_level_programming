#include "main.h"
/**
 * print_alphabet_x10 - main function
 * Return: always 0
 */

void print_alphabet_x10(void)
{
	int n;
	char a;

	for (n = 1 ; n <= 10 ; n++)
	{
		for (a = 'a' ; a <= 'z' ; a++)
			_putchar(a);
		_putchar('\n');
	}
}
