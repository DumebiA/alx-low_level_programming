#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - find the loop
 * @head: linked list
 *
 * Return: address of the 1st node, or NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_n = head, *fast_n = head;

	if (!head)
		return (NULL);

	while (slow_n && fast_n && fast_n->next)
	{
		slow_n = slow_n->next;
		fast_n = fast_n->next->next;
	if (slow_n == fast_n)
			{
				slow_n = slow_n->next;
				fast_n = fast_n->next;
			}
			return (fast_n);
	}
	return (NULL);
}
