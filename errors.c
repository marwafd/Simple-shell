#include "shell.h"

/**
 * _eput - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _eput(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputcharacter(str[i]);
		i++;
	}
}

/**
 * _eputcharacter - writes the character c to stderr
 * @c: The character to print.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputcharacter(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _eputfd - writes the character c to given fd.
 * @c: The character to print.
 * @fd: The filedescriptor to write to.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _eputsfd - prints an input string.
 * @str: the string to be printed.
 * @fd: the filedescriptor to write.
 * Return: the number of chars put.
 */
int _eputsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _eputfd(*str++, fd);
	}
	return (i);
}

