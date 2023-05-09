#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *local_buffer(char *filename);
void close_fildes(int fildes);

/**
 * local_buffer - allocates 1024 bytes.
 * @filename: The name of the file
 *
 * Return: A pointer to the newly-allocated buffer.
 */

char *local_buffer(char *filename)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buff);
}

/**
 * close_fildes - Closes file descriptors
 * @fildes: file descriptor
 */

void close_fildes(int fildes)
{
	int n;

	n = close(fildes);

	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fildes %d\n", fildes);
		exit(100);
	}
}

/**
 * main - main function
 * @argc: Arguments supplied to the program.
 * @argv: Array of pointers
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int source, des, x, r;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = local_buffer(argv[2]);
	source = open(argv[1], O_RDONLY);
	x = read(source, buff, 1024);
	des = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source == -1 || x == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		r = write(des, buff, x);
		if (des == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		x = read(source, buff, 1024);
		des = open(argv[2], O_WRONLY | O_APPEND);
	} while (x > 0);

	free(buff);
	close_fildes(source);
	close_fildes(des);
	return (0);
}
