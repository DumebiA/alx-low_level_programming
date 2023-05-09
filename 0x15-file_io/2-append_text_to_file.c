#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: Name of the file
 * @text_content: String to add to the end of the file
 *
 * Return: 1 on success and -1 on failure
 *         If filename is NULL return -1
 *         Otherwise - 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int opn, r, length = 0;

	if (filename == NULL)
		return (-1);

	else if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	opn = open(filename, O_WRONLY | O_APPEND);
	r = write(opn, text_content, length);

	if (opn == -1 || r == -1)
		return (-1);

	close(opn);

	return (1);
}
