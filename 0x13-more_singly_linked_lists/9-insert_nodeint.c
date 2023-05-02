#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node
 * @head: pointer to the first node
 * @idx: index where the new node is added
 * @n: data for newNode
 *
 * Return: pointer to the new node, or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int x;
	listint_t *tmp = *head;
	listint_t *newNode;


	newNode = malloc(sizeof(listint_t));
	if (!newNode || !head)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	for (x = 0; tmp && x < idx; x++)
	{
		if (x == idx - 1)
		{
			newNode->next = tmp->next;
			tmp->next = newNode;
			return (newNode);
		}
		else
			tmp = tmp->next;
	}

	return (NULL);
}
