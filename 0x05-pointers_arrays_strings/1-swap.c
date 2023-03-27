#include "main.h"
/**
 * swap_int - swaps the values of both int
 * @a: int to swap
 * @b: int to swap
 */

void swap_int(int *a, int *b)
{
	int n;

	n = *a;
	*a = *b;
	*b = n;
}
