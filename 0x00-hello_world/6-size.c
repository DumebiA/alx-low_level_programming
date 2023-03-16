#include <stdio.h>

/**
 * main - main function
 *
 * Return: should return 0
 */

int main(void)
{
	puts("Size of a char: %1u byte(s)", sizeof(char));
	puts("Size of an int: %1u byte(s)", sizeof(int));
	puts("Size of a long int: %1u byte(s)", sizeof(long int));
	puts("Size of a long long int: %1u byte(s)", sizeof(long long int));
	puts("Size of a float: %1u byte(s)", sizeof(float));
	return (0);
}
