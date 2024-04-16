#include "monty.h"
#include <stdio.h>
#include <string.h>
/**
 * add_stack_beg - it should add a node at the beginning of a stack_t
 * Return: returns the address of new node otherwise NULL
 */
stack_t *add_stack_beg(void)
{
	stack_t *tem = NULL;
	stack_t *head = element->head;

	tem = malloc(sizeof(stack_t));
	if (tem == NULL)
		return (NULL);
	tem->next = (head == NULL) ? NULL : head;
	tem->prev = NULL;
	if (head)
		head->prev = tem;
	element->head = tem;
	return (tem);
}
/**
  * get_toks - it should tokenize a line into separate strings
  * @buff: the buffer containing the line of strings
  * Return: void
  */
void get_toks(char *buff)
{
	char *tok;
	char *delim;
	int i;

	element->tokened[0] = NULL;
	element->tokened[1] = NULL;
	delim = " '\n'";
	tok = strtok(buff, delim);
	for (i = 0; tok != NULL && i < 2; i++)
	{
		element->tokened[i] = strdup(tok);
		if (element->tokened[i] == NULL)
			exit_function(3);
		tok = strtok(NULL, delim);
	}
}
/**
  * _push - pushes an element to the stack
  * @stack: it is a ptr to the top of the stack
  * @line_number: it is the line number of the command to be executed
  * Return: nothing
  */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int i = 0, f = 0, neg = 0;
	char *tem = element->tokened[1];

	(void) stack;
	(void) line_number;
	newnode = element->FO == 1 ? add_stack_end() : add_stack_beg();
	if (newnode == NULL)
		exit_function(3);
	if (tem != NULL)
	{
		if (tem[0] == '-')
		{
			i++;
			f = 1;
			neg = 1;
		}
		while (tem[i])
		{
			if (isdigit(tem[i]) == 0)
			{
				f = 1;
				break;
			}
			i++;
			f = 0;
		}
		if (f == 0)
		{
			if (neg == 1)
				tem = tem + 1;
			newnode->n = atoi(tem);
			if (neg == 1)
				newnode->n *= -1;
			return;
		}
	}
	exit_function(4);
}
/**
 * _pall - it should print all the values on the stack,from top
 *
 * @stack: it is the ptr to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = element->head;

	(void) stack;
	(void) line_number;
	if (head == NULL)
		return;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
/**
  * add_stack_end - it should add an element to the end of the stack
  * Return: returns address of new node, NULL otherwise
  */
stack_t *add_stack_end(void)
{
	stack_t *tem = NULL;
	stack_t *head = element->head;
	stack_t *trav;

	tem = malloc(sizeof(stack_t));
	if (tem == NULL)
		return (NULL);
	if (head == NULL)
	{
		free(tem);
		tem = add_stack_beg();
	}
	else
	{
		trav = head;
		while (trav->next != NULL)
			trav = trav->next;
		tem->next = NULL;
		tem->prev = trav;
		trav->next = tem;
	}
	return (tem);
}
