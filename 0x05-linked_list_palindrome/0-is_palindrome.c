#include "lists.h"

/**
* check_palindrome - check if the linked list is palindrome.
* @head: the pointer to head.
* @tmp: copy of the head.
* @len: pointer to store len of linked list
* @flag: ponter that check if list is different.
* Return: nothing.
*/

void check_palindrome(listint_t **head, listint_t *tmp, int *len, int *flag)
{
	*len += 1;
	if (tmp->next != NULL)
		check_palindrome(head, tmp->next, len, flag);

	if ((*head)->n == tmp->n)
	{
		*head = (*head)->next;
		*flag += 1;
	}
}

/**
* is_palindrome - checks if linked list is palindrome.
* @head: ponter to the head of lInked list.
* Return: 1 if is palindrome 0 if not.
*/

int is_palindrome(listint_t **head)
{
	listint_t *tmp = *head;
	listint_t *tmp2 = *head;
	int len = 0, flag = 0;

	if (*head == NULL)
		return (1);

	check_palindrome(&tmp, tmp2, &len, &flag);

	if (len == flag)
		return (1);
	return (0);
}
