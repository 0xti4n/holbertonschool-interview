#include "palindrome.h"

/**
* is_palindrome - checks is a palindrome.
* @n: number to check.
* Return: 1 if it is palindrome 0 if not.
*/

int is_palindrome(unsigned long n)
{
	static unsigned long last_number = 0, mod;

	if (n != 0)
	{
		mod = n % 10;
		last_number = (last_number * 10) + mod;
		is_palindrome(n / 10);
	}
	if (last_number == n)
		return (1);
	return (0);
}
