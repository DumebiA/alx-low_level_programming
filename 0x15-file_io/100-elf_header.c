#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *filename);
void print_magic(unsigned char *filename);
void print_class(unsigned char *filename);
void print_data(unsigned char *filename);
void print_version(unsigned char *filename);
void print_abi(unsigned char *filename);
void print_osabi(unsigned char *filename);
void print_type(unsigned int type, unsigned char *filename);
void print_entry(unsigned long int entry, unsigned char *filename);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file
 * @filename: A pointer to an array
 *
 * Description: If the file is not an ELF exit at 98.
 */

void check_elf(unsigned char *filename)
{
	int n;

	for (n = 0; n < 4; n++)
	{
		if (filename[n] != 127 &&
		    filename[n] != 'E' &&
		    filename[n] != 'L' &&
		    filename[n] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints magic numbers of an ELF header.
 * @filename: A pointer to an array
 *
 * Description: Magic numbers are separated by spaces.
 */

void print_magic(unsigned char *filename)
{
	int n;

	printf(" Magic: ");

	for (n = 0; n < INIDENT; n++)
	{
		printf("%02x", filename[n]);

		if (n == INIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints class of an ELF header.
 * @filename: A pointer to an array
 */

void print_class(unsigned char *filename)
{
	printf(" Class: ");

	switch (filename[CLASS])
	{
	case CLASS_NONE:
		printf("none\n");
		break;
	case CLASS_32:
		printf("ELF32\n");
		break;
	case CLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", filename[CLASS]);
	}
}

/**
 * print_data - Prints data of an ELF header.
 * @filename: A pointer to an array
 */

void print_data(unsigned char *filename)
{
	printf(" Data: ");

	switch (filename[DATA])
	{
	case DATA_NONE:
		printf("none\n");
		break;
	case DATA_2LSB:
		printf("2's complement, little endian\n");
		break;
	case DATA_2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", filename[CLASS]);
	}
}

/**
 *  * print_version - Prints the version of an ELF header.
 *   * @filename: A pointer to an array
 *    */

void print_version(unsigned char *filename)
{
	 printf(" Version: %d",
			  filename[VERSION]);

	switch (filename[VERSION])
	{
	case CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints OS/ABI of an ELF header.
 * filename: A pointer to an array
 */

void print_osabi(unsigned char *filename)
{
	printf(" OS/ABI: ");

	switch (filename[OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", filename[OSABI]);
	}
}

/**
 * print_abi - Prints ABI version of an ELF header.
 * @filename: A pointer to an array
 */

void print_abi(unsigned char *filename)
{
	printf(" ABI Version: %d\n",
		filename[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @type: The ELF type.
 * @filename: A pointer to an array containing the ELF class.
 */

void print_type(unsigned int type, unsigned char *filename)
{
	if (filename[DATA] == DATA_2MSB)
		type >>= 8;

	printf(" Type: ");

	switch (type)
	{
	case NONE:
		printf("NONE (None)\n");
		break;
	case REL:
		printf("REL (Relocatable file)\n");
		break;
	case EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case DYN:
		printf("DYN (Shared object file)\n");
		break;
	case CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @filename: The address of the ELF entry point.
 * @entry: A pointer to an array containing the ELF class.
 */

void print_entry(unsigned long int entry, unsigned char *filename)
{
	printf(" Entry point address: ");

	if (filename[DATA] == DATA_2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (filename[CLASS] == CLASS_32)
		printf("%#x\n", (unsigned int)entry);

	else
		printf("%#lx\n", entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in ELF file
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *head;
	int n, r;

	n = open(argv[1], O_RDONLY);
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	head = malloc(sizeof(Elf64_Ehdr));
	else if (head == NULL)
	{
		close_elf(n);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(n, head, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(head);
		close_elf(n);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(head->filename);
	printf("ELF Header:\n");
	print_magic(head->filename);
	print_class(head->filename);
	print_data(head->filename);
	print_version(head->filename);
	print_osabi(head->filename);
	print_abi(head->filename);
	print_type(head->type, head->filename);
	print_entry(head->entry, head->filename);

	free(head);
	close_elf(n);
	return (0);
}
