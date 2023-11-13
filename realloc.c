#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _memset - Fills memory with a constant byte
 * @b: byte to fill *s with
 * @s: Pointer to memory area
 * @n: Amount of bytes to be filled
 *
 * By : Jojo-Programming
 * Return: (s) a pointer to the memory area s
 */

	char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	s[i] = b;
	return (s);
}

/**
 * Free - This Frees a string of strings
 * @pp: String of strings
 *
 */

	void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
	return;

	while (*pp)
	free(*pp++);
	free(a);
}

/**
 * _realloc - Reallocates a block of memory
 * @ptr: Pointer to previous malloc'ated block
 * @old_size: Byte size of previous block
 * @new_size: Byte size of new block
 *
 * By : Jojo-Programming
 * Return: pointer to the reallocated block or
 * NULL on failure
 */

	void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
	return (malloc(new_size));

	if (!new_size)
	return (free(ptr), NULL);

	if (new_size == old_size)
	return (ptr);

	p = malloc(new_size);

	if (!p)
	return (NULL);

	old_size = old_size < new_size ? old_size : new_size;

	memcpy(p, ptr, old_size);
	free(ptr);

	return (p);
}
