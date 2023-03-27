#include "main.h"

/**
 * rev_string - Reverse string
 * @s: Input string
 * Return: String reverse hehehe
 */

void rev_string(char *s)
{
	char rev = s[0];
	int checker = 0;
	int n;

	while (s[checker] != '\0')
	checker++;
	for (n = 0; n < checker; n++)
	{
		checker--;
		rev = s[n];
		s[n] = s[checker];
		s[checker] = rev;
	}
}
