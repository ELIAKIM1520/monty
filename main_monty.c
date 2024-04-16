#include "monty.h"
all_vars_t *element;
/**
  * main - entry point
  * @argc: its the number of arguments
  * @argv: its the argument names
  * Return: on succes (0), exit on failure
  */
int main(int argc, char **argv)
{
	size_t n = 0;
	all_vars_t tem = {0, NULL, NULL, NULL, NULL, NULL, 1};

	element = &tem;
	element->f_name = argv[1];
	if (argc != 2)
		exit_function(16);
	element->fp = fopen(argv[1], "r");
	if (element->fp == NULL)
		exit_function(1);
	for (; getline(&(element->buff), &n, element->fp) != EOF;
			element->line_number++)
	{
		element->tokened = malloc(sizeof(char *) * 2);
		if (element->tokened == NULL)
			exit_function(3);
		get_toks(element->buff);
		opcode_getter();
		free_buf();
		free_token();
	}
	free_buf();
	l_free(element->head);
	free_token();
	fclose(element->fp);
	return (0);
}
