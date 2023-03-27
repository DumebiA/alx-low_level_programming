#include "main.h"

/**
 * print_array - function that prints element
 * @a: array
 * @n: number of elements to be printed
 * Return: a and n
 */
void print_array(int *a, int n)
{
	int o;

	for (o = 0; o < (n - 1); o++)
	{
		printf("%d, ", a[o]);
	}
		if (o == (n - 1))
		{
			printf("%d", a[n - 1]);
		}
			printf("\n");
}
