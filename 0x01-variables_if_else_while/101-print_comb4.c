#include <stdio.h>
/**
 * main - main function
 * Return: always 0
 */

int main(void)
{
	int m;
	int n;
	int o;

	for (m = 0 ; m < 10 ; m++)
	{
		for (n = 1 ; n < 10 ; n++)
		{
			for (o = 2 ; o < 10 ; o++)
			{
				if (m < n && n < o)
				{
					putchar(m + '0');
					putchar(n + '0');
					putchar(o + '0');
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
