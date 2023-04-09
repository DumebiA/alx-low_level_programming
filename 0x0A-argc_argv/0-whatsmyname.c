#include <stdio.h>
#include "main.h"

/**
 * main - prints main name
 * @argc: number argument
 * @argv: array argument
 *
 * Return: Always 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
