#include "main.h"

/**
 * print_chessboard - Entry point
 * @a: array
 * Return: Always 0 (Success)
 */

void print_chessboard(char (*a)[8])
{
	int n;
	int o;

	for (n = 0; n < 8; n++)
	{
		for (o = 0; o < 8; o++)
			_putchar(a[n][o]);
		_putchar('\n');
	}
}
