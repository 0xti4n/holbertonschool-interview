#include "lists.h"

/**
* check_cycle - Checks if a singly linked list has a cycle in it.
* @list: the node.
* Return: 0 if it has no cycle, otherwise 1.
*/

int check_cycle(listint_t *list)
{
	listint_t *tmp1 = list;
	listint_t *tmp2 = list;

	while (tmp1 && tmp1->next && tmp2 != NULL)
	{
		tmp1 = tmp1->next->next;
		tmp2 = tmp2->next;

		if (tmp1 == tmp2)
			return (1);
	}
	return (0);
}
