#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * _a - reallocates memory for ponters
 * @list: Old list
 * @size: size of new list
 * @new: new node for list
 *
 * Return: point to new list
 */

const listint_t **_a(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **newList;
	size_t n;

	newList = malloc(size * sizeof(listint_t *));
	if (newList == NULL)
	{
		free(list);
		exit(98);
	}
	for (n = 0; n < size - 1; n++)
		newList[n] = list[n];
	newList[n] = new;
	free(list);
	return (newList);
}

/**
 * print_listint_safe - prints list
 * @head: pointer
 *
 * Return: number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t n, value = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (n = 0; n < value; n++)
		{
			if (head == list[n])
			{
				printf("[%p] %d\n", (void *)head, head->n);
				free(list);
				return (value);
			}
		}
		value++;
		list = _a(list, value, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (value);
}
