#include "monty.h"
/**
  * _add - it adds two ints of the stack
  * @stack: its the pointer to the top of the stack
  * @line_number: the line nimber of the command being executed
  * Return: nothing
  */
void _add(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	if (element->head != NULL && element->head->next != NULL)
	{
		element->head->next->n = element->head->n + element->head->next->n;
		_pop(NULL, 0);
	}
	else
	{
		exit_function(8);
	}
}
/**
  * _sub - it subtracts the top element of the stack from the second top
  * @stack: pointer to the top of the stack
  * @line_number: the line number of the command being executed
  * Return: nothing
  */
void _sub(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	if (element->head != NULL && element->head->next != NULL)
	{
		element->head->next->n = element->head->next->n - element->head->n;
		_pop(NULL, 0);
	}
	else
	{
		exit_function(9);
	}
}
/**
 * _divide - it divides the second top element of the stack by the top
 * @stack: its a ptr to the top of the stack
 * @line_number: its the line number of the command being execute
 * Return: void, nothing
 */
void _divide(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	if (element->head != NULL && element->head->next != NULL)
	{
		if (element->head->n == 0)
			exit_function(13);
		element->head->next->n /= element->head->n;
		_pop(NULL, 0);
	}
	else
	{
		exit_function(10);
	}
}
/**
 * _mul - it does multiplies the second top element of the stack with top
 * @stack: it is the ptr to the top of the stack
 * @line_number: it is the line number of the command being execute
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	if (element->head != NULL && element->head->next != NULL)
	{
		element->head->next->n *= element->head->n;
		_pop(NULL, 0);
	}
	else
	{
		exit_function(11);
	}
}
/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: ptr to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (element->head != NULL && element->head->next != NULL)
	{
		if (element->head->n == 0)
			exit_function(13);
		element->head->next->n = element->head->next->n % element->head->n;
		_pop(NULL, 0);
	}
	else
	{
		exit_function(12);
	}
}
