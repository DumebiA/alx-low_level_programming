#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - function returns the number of elements in a linked lists
 * @h: linked list listint_t to return
 *
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t value = 0;

while (h)
{
	value++;
	h = h->next;
}

return (value);
}
