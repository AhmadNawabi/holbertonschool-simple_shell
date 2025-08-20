#include "main.h"

/**
 * exec_line - Finds and executes builtins or external commands
 * @datash: Pointer to the data_shell structure containing args
 *
 * Description:
 * This function checks if the first argument entered
 * by the user matches a builtin command. If so, it
 * executes the builtin. Otherwise, it calls cmd_exec()
 * to execute the command as an external program.
 *
 * Return: 1 on success or continuation of shell loop.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
