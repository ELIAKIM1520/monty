#include "monty.h"
/**
  * _pstr - it should print the string starting at the top of the stack
  * @stack: it is the double pointer to the beginning of the list
  * @line_number: it is the line of the file it's on (always passed 0)
  * Return: return nothing
  */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *trav;

	(void) stack;
	(void) line_number;
	trav = element->head;
	while (trav != NULL)
	{
		if (trav->n < 1 || trav->n > 127)
			break;
		putchar(trav->n);
		trav = trav->next;
	}
	putchar('\n');
}
/**
  * _pchar - it should print the char at the top of the stack, then \n
  * @stack: the double pointer to the beginning of the list (NULL)
  * @line_number: the line of the file it's on (always passed 0)
  * Return: nothing, void
  */
void _pchar(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (element->head == NULL)
		exit_function(15);
	if (element->head->n < 0 || element->head->n > 127)
		exit_function(14);
	putchar(element->head->n);
	putchar('\n');
}
/**
 * _rotl - it rotates the stack to the top
 * @stack: it is the ptr to the top of the stack
 * @line_number: it is the the line number of the command being execute
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *end;
	stack_t *head;

	end = element->head;
	head =  element->head;
	(void) stack;
	(void) line_number;
	if (end && end->next)
	{
		while (end->next != NULL)
			end = end->next;
		element->head = head->next;
		head->prev = end;
		head->next = NULL;
		end->next = head;
		element->head->prev = NULL;
	}
}
/**
 * _rotr - it should rotate the stack to the bottom
 * @stack: it is a pointer to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *end, *head;

	end = element->head;
	head = element->head;
	(void) stack;
	(void) line_number;
	if (end && end->next)
	{
		while (end->next)
			end = end->next;
		end->prev->next = NULL;
		head->prev = end;
		end->next = head;
		end->prev = NULL;
		element->head = end;

	}
}
