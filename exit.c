#include "shell.h"

/**
 **_strcpy - copy a string.
 *@dest: the destination string to be copied to the source string.
 *@src: the source string.
 *@n: the amount of characters to be copied.
 *Return: the concatenated string.
 */
char *_strcpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strcat - concatenates two strings.
 *@dest: the first string.
 *@src: the second string.
 *@n: the amount of bytes to be maximally used.
 *Return: the concatenated string.
 */
char *_strcat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchar - locates a character in a string.
 *@s: the string to be parsed.
 *@c: the character to look for.
 *Return: (s) a pointer to the memory area s.
 */
char *_strchar(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

