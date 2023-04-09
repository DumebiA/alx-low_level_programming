#include <stdio.h>
#include "main.h"

/**
 * main - print main number of arguments
 * @argc: number argument
 * @argv: array argument
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
(void) argv; /*Ignore argv*/
	printf("%d\n", argc - 1);

	return (0);
}
