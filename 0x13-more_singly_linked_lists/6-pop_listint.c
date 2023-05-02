#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node
 * @head: pointer
 *
 * Return: if data inside the elements that was deleted, 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int data;

	if (!head || !*head)
		return (0);

	data = (*head)->n;
	tmp = (*head)->next;
	free(*head);

	*head = tmp;

	return (data);
}
