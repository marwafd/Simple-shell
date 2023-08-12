#include "shell.h"

/**
 * pfree - frees a pointer and NULLs the address.
 * @ptr : adress of the pointer to free.
 *
 * Return: 1 if free, otherwise 0.
 **/
int pfree(void **ptr)
{

	int(ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
