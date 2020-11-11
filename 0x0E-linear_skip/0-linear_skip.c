#include "search.h"

/**
* linear_skip - searches for a value in a sorted skip list of integers
* @list: list to find the value
* @value: value to search
* Return: pointer to the node where value is located
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *aux;
	size_t idx, idx2;

	if (!list)
		return (NULL);

	while (list->next && list->n < value)
	{
		if (list->express)
		{
			aux = list;
			list = list->express;
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			if (!list->express && value > list->n)
				aux = list;
		}
		else
			list = list->next;
	}
	idx = aux->index;
	idx2 = list->index;
	printf("Value found between indexes [%lu] and [%lu]\n", idx, idx2);
	while (aux->next && aux->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", aux->index, aux->n);
		aux = aux->next;
		if (!aux->next)
			printf("Value checked at index [%lu] = [%d]\n", aux->index, aux->n);
	}
	if (aux->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", aux->index, aux->n);
		return (aux);
	}
	return (NULL);
}
