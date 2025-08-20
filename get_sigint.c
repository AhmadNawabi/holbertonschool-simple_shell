#include "main.h"

/**
 * get_sigint - Handles SIGINT (Ctrl + C) signal
 * @sig: Signal value (unused)
 *
 * Description:
 * This function captures the Ctrl + C interrupt signal
 * and prevents the shell from closing. Instead, it
 * prints a new prompt on a fresh line, allowing the
 * user to continue using the shell.
 *
 * Return: Nothing
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
