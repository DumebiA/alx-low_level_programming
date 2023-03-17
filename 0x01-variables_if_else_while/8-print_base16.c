#include <stdio.h>

/**
 * main - main function
 *
 * Return: always 0
 */

int main(void)
{
	int n;
	char o;

	for (n = 0 ; n < 10 ; n++)
		putchar(n + '0');
	for (o = 'a' ; o <= 'f' ; o++)
		putchar(o);
	putchar('\n');
	return (0);
}
