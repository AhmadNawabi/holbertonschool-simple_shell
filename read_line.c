#include "main.h"

/**
 * read_line - Reads a line of input from stdin
 * @i_eof: Pointer to variable that stores the return
 *         value of getline (EOF check)
 *
 * Description:
 * Uses the getline function to read an input line
 * from stdin. The return value of getline is stored
 * in *i_eof to check for EOF (-1).
 *
 * Return: Pointer to the input string on success,
 *         or NULL on failure/EOF.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
