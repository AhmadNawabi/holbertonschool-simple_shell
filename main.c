#include "main.h"

/**
 * free_data - Frees memory used by the data structure
 * @datash: Pointer to data_shell structure
 *
 * Description:
 * This function releases the memory allocated for the
 * environment variables and the process ID string
 * stored in the data_shell structure.
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - Initializes data_shell structure with default values
 * @datash: Pointer to data_shell structure
 * @av: Argument vector from main
 *
 * Description:
 * Initializes the data_shell structure with program arguments,
 * environment variables, process ID, and default values
 * for input, args, status, and counter.
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));
	if (datash->_environ == NULL)
		return;

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
		if (datash->_environ[i] == NULL)
			return;
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point of the shell program
 * @ac: Argument count
 * @av: Argument vector
 *
 * Description:
 * Initializes the data_shell structure and starts the
 * main shell loop. Frees resources before exit.
 *
 * Return: 0 on success, 255 on failure, or shell status.
 */
int main(int ac, char **av)
{
	data_shell datash;

	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);

	if (datash.status < 0)
		return (255);

	return (datash.status);
}
