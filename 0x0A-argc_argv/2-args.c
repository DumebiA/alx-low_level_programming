#include <stdio.h>
#include "main.h"

/**
 * main - prints all arguments
 * @argc: number argument
 * @argv: array argument
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int n;

	for (n = 0; n < argc; n++)
	{
		printf("%s\n", argv[n]);
	}

	return (0);
}
