#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters
 * Return: when actual number of bytes read and print return r, 0 when function fails
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *text;
	ssize_t fildes, r, o;

	fildes = open(filename, O_RDONLY);
	if (fildes == -1)
		return (0);

	text = malloc(sizeof(char) * letters);
	o = read(fildes, text, letters);
	r = write(STDOUT_FILENO, text, o);

	free(text);
	close(fildes);
	return (r);
}
