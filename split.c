#include "main.h"

/**
 * swap_char - Swaps '|' and '&' with non-printed chars
 * @input: Input string
 * @bool: Swap type (0 = encode, 1 = decode)
 *
 * Description:
 * Used internally to distinguish single '|' and '&'
 * characters from their logical forms '||' and '&&'.
 *
 * Return: Pointer to the modified string.
 */
char *swap_char(char *input, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * add_nodes - Adds separators and commands to linked lists
 * @head_s: Head of separator list
 * @head_l: Head of command line list
 * @input: Input string
 *
 * Description:
 * Parses the input string, storing separators (';', '|', '&')
 * in one list and command lines in another.
 *
 * Return: Nothing.
 */
void add_nodes(sep_list **head_s, line_list **head_l, char *input)
{
	int i;
	char *line;

	input = swap_char(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			add_sep_node_end(head_s, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			add_sep_node_end(head_s, input[i]);
			i++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = swap_char(line, 1);
		add_line_node_end(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);
}

/**
 * go_next - Moves to the next command line in list
 * @list_s: Pointer to separator list
 * @list_l: Pointer to command line list
 * @datash: Pointer to data_shell structure
 *
 * Description:
 * Determines the next command to execute based on
 * logical separators (&&, ||, ;) and the last status.
 *
 * Return: Nothing.
 */
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int loop_sep = 1;
	sep_list *ls_s = *list_s;
	line_list *ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
			{
				ls_l = ls_l->next;
				ls_s = ls_s->next;
			}
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
			{
				ls_l = ls_l->next;
				ls_s = ls_s->next;
			}
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - Splits command lines by separators
 * @datash: Pointer to data_shell structure
 * @input: Input string
 *
 * Description:
 * Splits the input string using separators (;, |, &),
 * stores them in lists, and executes each command line.
 *
 * Return: 0 if "exit" is called, 1 otherwise.
 */
int split_commands(data_shell *datash, char *input)
{
	sep_list *head_s = NULL, *list_s;
	line_list *head_l = NULL, *list_l;
	int loop;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = split_line(datash->input);
		loop = exec_line(datash);
		free(datash->args);

		if (loop == 0)
			break;

		go_next(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_line_list(&head_l);

	if (loop == 0)
		return (0);

	return (1);
}

/**
 * split_line - Tokenizes the input string into arguments
 * @input: Input string
 *
 * Description:
 * Splits the input string into an array of tokens (arguments)
 * using delimiters defined in TOK_DELIM.
 *
 * Return: Array of tokenized strings.
 */
char **split_line(char *input)
{
	size_t bsize = TOK_BUFSIZE;
	size_t i;
	char **tokens;
	char *token;

	tokens = malloc(sizeof(char *) * bsize);
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
