#include "shell.h"

/**
 * free_buffers - frees buffers
 * @buf: buffer to be freed
 *
 * Return: no return
 */
void free_buffers(char **buffer)
{
	int i = 0;

	if (buffer == NULL || !buffer)
		return;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
