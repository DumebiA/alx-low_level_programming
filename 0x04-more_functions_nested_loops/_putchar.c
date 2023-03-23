#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes c to stdout
 * @c: Print character
 * Return: On success 1.
 * On error, -1 is returned, and errno is made.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
