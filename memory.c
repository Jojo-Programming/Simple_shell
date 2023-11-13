#include "shell.h"

/**
 * bfree - Frees a pointer & NULLs the address
 * @ptr: the address  of the pointer to free
 *
 * By : Jojo-Programming
 * Return: 1 if freed, otherwise 0.
 */

	int bfree(void **ptr)
{
	if (ptr && *ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (1);
}
	return (0);
}
