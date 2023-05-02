#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node
 * @head: pointer
 * @index: index of the node to delete
 *
 * Return: 1 if successful, or -1 if fail
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int n = 0;
	listint_t *tmp = *head;
	listint_t *node = NULL;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	while (n < index - 1)
	{
		if (!tmp || !(tmp->next))
			return (-1);
		tmp = tmp->next;
		n++;
	}


	node = tmp->next;
	tmp->next = node->next;
	free(node);

	return (1);
}
