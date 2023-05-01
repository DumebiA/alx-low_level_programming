#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - function prints all the elements of listint_t
 * @h: linked list to print
 *
 * Return: number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t value = 0;

	while (h)
	{
		printf("%d\n", h->n);
		value++;
		h = h->next;
	}

	return (value);
}
