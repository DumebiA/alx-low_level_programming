#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms
 * followed by a new line
 * Return: always 0
 */

int main(void)
{
	int n;
	unsigned long int o, p, next, sum;

	o = 1;
	p = 2;
	sum = 0;

	for (n = 1; n <= 33; ++n)
	{
		if (o < 4000000 && (o % 2) == 0)
		{
			sum = sum + o;
		}
		next = o + p;
		o = p;
		p = next;
	}

	printf("%lu\n", sum);

	return (0);
}
