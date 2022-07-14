#include "monty.h"

/**
  * opcode_search - searches for opcode in struct
  * Return: Nothing, void
  */
void opcode_search(void)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"div", divide},
		{"add", add},
		{"swap", swap},
		{"mul", mul},
		{"mod", mod},
		{"sub", sub},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", lifo},
		{"queue", fifo},
		{NULL, NULL}
	};

	int x;

	if (element->tokened[0] == NULL)
		return;
	if (element->tokened[0][0] == '#')
	{
		ops[10].f(NULL, 0);
		return;
	}
	for (x = 0; ops[x].opcode != NULL; x++)
	{
		if (strcmp(element->tokened[0], ops[x].opcode) == 0)
		{
			ops[x].f(NULL, 0);
			break;
		}
	}
	if (ops[x].opcode == NULL)
		exit_function(2);
}
