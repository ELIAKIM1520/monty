#include "monty.h"

/**
  * _pint - it should print the value at the top of the stack
  * @stack: it is the pointer to the top of the stack
 * @line_number: the line number of the command being execute
  * Return: returns nothing
  */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (element->head == NULL)
		exit_function(5);
	printf("%d\n", element->head->n);
}
/**
 * _swap - it swaps the top two elements of the stack
 * @stack: it is the pointer to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int tem = 0;

	(void) stack;
	(void) line_number;
	if (element->head != NULL && element->head->next != NULL)
	{
		tem = element->head->n;
		element->head->n = element->head->next->n;
		element->head->next->n = tem;
	}
	else
	{
		exit_function(7);
	}
}
/**
  * _pop - it removes the top element of the stack
  * @stack: it is the poitr to the top of the stack
  * @line_number: the line number of the command being execute
  * Return: nothing, void
  */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *trav;

	(void) line_number;
	(void) stack;

	if (element->head == NULL)
		exit_function(6);
	trav = element->head->next;
	if (trav != NULL)
		trav->prev = NULL;
	free(element->head);
	element->head = trav;
}
/**
  * _nop - doesn’t do anything
  * @stack: ptr to the top of the stack
  * @line_number: the line number of the command being execute
  * Return: void
  */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
