#include <stdio.h>

/**
 * main - main function
 *
 * Return: always 0
 */

int main(void)
{
	int n;
	int o;

	for (n = 0 ; n < 10 ; n++)
	{
		for (o = 1 ; o < 10 ; o++)
		{
			if (n < o && n != o)
			{
				putchar(n + '0');
				putchar(o + '0');
				if (n + o != 17)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
