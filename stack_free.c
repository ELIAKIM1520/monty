
#include "monty.h"

/**
 * exit_function - it should handle errors and free memory before exiting
 * @err_int: its the number corresponding to an error message
 * Return: void
 */
void exit_function(unsigned int err_int)
{
	char *str[] = {"swap", "add", "sub", "div", "mul", "mod"};
	int ln = element->line_number;

	if (err_int == 1)
		fprintf(stderr, "Error: Can't open file %s\n", element->f_name);
	if (err_int == 2)
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, element->tokened[0]);
	if (err_int == 3)
		fprintf(stderr, "Error: malloc failed\n");
	if (err_int == 4)
		fprintf(stderr, "L%d: usage: push integer\n", ln);
	if (err_int == 5)
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
	if (err_int == 6)
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
	if (err_int >= 7 && err_int <= 12)
		fprintf(stderr, "L%d: can't %s, stack too short\n", ln, str[err_int - 7]);
	if (err_int == 13)
		fprintf(stderr, "L%d: division by zero\n", ln);
	if (err_int == 14)
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
	if (err_int == 15)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
	if (err_int == 16)
		fprintf(stderr, "USAGE: monty file\n");
	free_buf();
	l_free(element->head);
	free_token();
	if (element->fp != NULL)
		fclose(element->fp);
	exit(EXIT_FAILURE);
}
/**
 * l_free - free a stack_t list
 * @head: head of list to free
 * Return: void
 */
void l_free(stack_t *head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			l_free(head->next);
		free(head);
	}
}
/**
 * free_buf - free getline buffer
 * Return: void
 */
void free_buf(void)
{
	if (element->buff != NULL)
	{
		free(element->buff);
		element->buff = NULL;
	}
}
/**
  * free_token - Frees malloc'd tokens
  * Return: Nothing, void
  */
void free_token(void)
{
	if (element->tokened != NULL)
	{
		if (element->tokened[0] != NULL)
			free(element->tokened[0]);
		if (element->tokened[1] != NULL)
			free(element->tokened[1]);
		free(element->tokened);
	}
	element->tokened = NULL;
}
