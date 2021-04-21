#include "substring.h"

/**
 * cmp_values - Function that compare two values
 * @a: first value
 * @b: second value
 * Return: substraction
**/

int cmp_values(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

/**
 * check_words - Function that chek if all words are continous
 * @aux_indx: array with index for ever word
 * @len_word: word size
 * @idx_len: aux_indx size
 * Return: index firt word or zero
**/

int check_words(int *aux_indx, int len_word, int idx_len)
{
	int i;

	for (i = 0; i < idx_len - 1; i++)
	{
		if (aux_indx[i + 1] - aux_indx[i]  != len_word)
			return (0);
	}
	return (1);
}

/**
 * search_word - Function that search words in string
 * @s: string base
 * @words: array of words to search in the string
 * @nb_words: number of words
 * Return: array with size of substring for every word, otherwise NULL
**/

int *search_word(char const *s, char const **words, int nb_words)
{
	int *aux_idx, i, j;
	char *aux;
	int ln;

	aux_idx = malloc((sizeof(int) * nb_words));
	if (!aux_idx)
		return (NULL);
	for (i = 0; i < nb_words; i++)
	{
		aux = strstr(s, words[i]);
		if (!aux)
		{
			free(aux_idx);
			return (NULL);
		}
		ln = (int)strlen(aux);
		for (j = 0; j < i; j++)
		{
			if (ln == aux_idx[j])
			{
				aux = strstr(s + (int)strlen(s) - ln + 1, words[i]);
				if (!aux)
				{
					free(aux_idx);
					return (NULL);
				}
				ln = (int)strlen(aux);
				aux_idx[i] = ln;
				continue;
			}
		}
		aux_idx[i] = ln;
	}
	return (aux_idx);
}

/**
 * find_substring - Function that search_word words in string
 * @s: string base
 * @words: array of words to searh in the string
 * @nb_words: number of words
 * @n: return size
 * Return: array with index for every word or NULL
 *
**/

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *idx, *aux_idx, len_word, i, diff, s_len, f_idx, tmp;

	*n = 0;
	len_word = (int)strlen(words[0]);
	s_len = (int)strlen(s);

	for (i = 0; i < s_len; i++)
	{
		aux_idx = search_word(s, words, nb_words);
		if (!aux_idx)
			break;
		qsort(aux_idx, nb_words, sizeof(int), cmp_values);
		f_idx = check_words(aux_idx, len_word, nb_words);
		tmp = aux_idx[nb_words - 1];
		free(aux_idx);
		if (f_idx == 1)
		{
			diff = s_len - tmp;
			if (*n == 0 || diff != idx[*n - 1])
			{
				if (*n == 0)
				{
					idx = malloc((sizeof(int)));
					if (!idx)
						return (NULL);
				}
				else
					idx = realloc(idx, sizeof(int) * (*n + 1));
				idx[*n] = diff;
				*n += 1;
			}
		}
		s++;
	}
	if (*n == 0)
		return (NULL);
	return (idx);
}
