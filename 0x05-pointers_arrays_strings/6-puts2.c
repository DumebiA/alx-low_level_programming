#include "main.h"
/**
 * puts2 - function should print only one char of two
 * starting with first
 * @str: ivariable
 * Return: print success
 */
void puts2(char *str)
{
	int li = 0;
	int n = 0;
	char *m = str;
	int o;

	while (*m != '\0')
	{
		m++;
		li++;
	}
	n = li - 1;
	for (o = 0 ; o <= n ; o++)
	{
		if (o % 2 == 0)
	{
		_putchar(str[o]);
	}
	}
	_putchar('\n');
}
