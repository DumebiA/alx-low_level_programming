#include "main.h"

/**
 * jack_bauer - prints every minute of the day of Jack Bauer
 * starting from 00:00 to 23:59
 */

void jack_bauer(void)
{
	int i, n;

	i = 0;

	while (i < 24)
	{
		n = 0;

		while (n < 60)
		{
			_putchar((i / 10) + '0');
			_putchar((i % 10) + '0');
			_putchar(':');
			_putchar((n / 10) + '0');
			_putchar((n % 10) + '0');
			_putchar('\n');
			n++;
		}
		i++;
	}
}
