#include "lists.h"

/**
 * loop - check the code.
 * @tortoise: pointer one by one
 * @hare: pointer one more
 * Return: pointer where the loop start
*/

listint_t *check_loop(listint_t *tortoise, listint_t *hare)
{
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
	}
	return (tortoise);
}

/**
 * find_listint_loop - finds loops inside lists
 * @head: pointer head
 * Return: number of nodes
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	if (head)
	{
		tortoise = head->next;
		hare = head->next->next;
		while (tortoise && hare)
		{
			if (tortoise == hare)
			{
				tortoise = head;
				return (check_loop(tortoise, hare));
			}
			tortoise = tortoise->next;
			hare = hare->next->next;
		}
	}
	return (0);
}
