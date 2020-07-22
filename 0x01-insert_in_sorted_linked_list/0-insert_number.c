#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* add_node_new - inserts a number into a sorted singly linked list.
* @head: the nodes.
* @number: the number to insert.
* @new: the number to insert.
* Return: the address of the new node, or NULL if it failed.
*/

listint_t *add_node_new(listint_t **head, int number, listint_t **new)
{
	listint_t *t1, *tmp;

	t1 = *head;
	tmp = NULL;
	while (t1->next != NULL)
	{
		if (number == t1->n)
			return (*head);
		else if (number < t1->n)
		{
			(*new)->next = t1;
			*head = *new;
			return (*head);
		}
		else if (number > t1->n && number < t1->next->n)
		{
			tmp = t1->next;
			t1->next = *new;
			(*new)->next = tmp;
			return (*head);
		}
		else if (number > t1->next->n && t1->next->next == NULL)
		{
			t1->next->next = *new;
			return (*head);
		}
		t1 = t1->next;
	}
	return (*head);
}

/**
* insert_node - inserts a number into a sorted singly linked list.
* @head: the nodes.
* @number: the number to insert.
* Return: the address of the new node, or NULL if it failed.
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *t1, *new;

	if (*head != NULL)
	{
		t1 = *head;
		new = malloc(sizeof(listint_t));
		if (new == NULL)
			return (NULL);

		new->n = number;
		new->next = NULL;

		if (t1->next == NULL)
		{
			if (number > t1->n)
			{
				t1->next = new;
				return (*head);
			}
			new->next = t1;
			*head = new;
			return (*head);
		}
		add_node_new(head, number, &new);
	}
	return (NULL);
}
