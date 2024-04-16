#include "monty.h"

/**
 * opcode_getter - it should select the correct opcode to perform
 *
 * Return: nothing
 */
void opcode_getter(void)
{
	instruction_t instr_ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"div", _divide},
		{"add", _add},
		{"swap", _swap},
		{"mul", _mul},
		{"mod", _mod},
		{"sub", _sub},
		{"nop", _nop},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _lifo},
		{"queue", _fifo},
		{NULL, NULL}
	};
	int l;

	if (element->tokened[0] == NULL)
		return;
	if (element->tokened[0][0] == '#')
	{
		instr_ops[10].f(NULL, 0);
		return;
	}
	for (l = 0; instr_ops[l].opcode != NULL; l++)
	{
		if (strcmp(element->tokened[0], instr_ops[l].opcode) == 0)
		{
			instr_ops[l].f(NULL, 0);
			break;
		}
	}
	if (instr_ops[l].opcode == NULL)
		exit_function(2);
}
