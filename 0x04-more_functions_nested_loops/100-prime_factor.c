#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 * Return: Always 0
 */

int main(void)
{
	long int n;
	long int max;
	long int m;

	n = 612852475143;
	max = -1;

	while (n % 2 == 0)
	{
		max = 2;
		n /= 2;
	}

	for (m = 3; m <= sqrt(n); m = m + 2)
	{
		while (n % m == 0)
		{
			max = m;
			n = n / m;
		}
	}

	if (n > 2)
		max = n;

	printf("%ld\n", max);

	return (0);
}
