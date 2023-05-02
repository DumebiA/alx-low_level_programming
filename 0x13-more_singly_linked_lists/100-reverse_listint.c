#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer
 *
 * Return: pointer to the first node in the new list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *last = NULL;
	listint_t *pres = *head;
	listint_t *next = NULL;

	while (pres != NULL)
	{
		next = pres->next;

		pres->next = last;

		last = pres;
		pres = next;
	}
	*head = last;

	return (*head);
}
