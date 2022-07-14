#include "monty.h"
/**
 * add_stack_init - add a node at the beggining of a stack_t
 * Return: Address of new node or NULL if failed
 */
stack_t *add_stack_init(void)
{
	stack_t *temp = NULL;
	stack_t *head = element->head;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		return (NULL);
	temp->next = (head == NULL) ? NULL : head;
	temp->prev = NULL;
	if (head)
		head->prev = temp;
	element->head = temp;
	return (temp);
}

/**
  * get_tokens - tokenizes a line into separate strings
  * @buf: the buffer containing the line of strings
  * Return: void
  */
void get_tokens(char *buf)
{
	char *token;
	char *delim;
	int i;

	element->tokened[0] = NULL;
	element->tokened[1] = NULL;
	delim = " '\n'";
	token = strtok(buf, delim);
	for (i = 0; token != NULL && i < 2; i++)
	{
		element->tokened[i] = strdup(token);
		if (element->tokened[i] == NULL)
			exit_function(3);
		token = strtok(NULL, delim);
	}
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: ptr to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = element->head;

	(void) stack;
	(void) line_number;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}

}

/**
 * push - pushes an element to the stack
 * @stack: ptr to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int i = 0, f = 0, negative = 0;
	char *temp = element->tokened[1];

	(void) stack;
	(void) line_number;
	newnode = element->IFO == 1 ? add_stack_end() : add_stack_init();
	if (newnode == NULL)
		exit_function(3);
	if (temp != NULL)
	{
		if (temp[0] == '-')
		{
			i++;
			f = 1;
			negative = 1;
		}
		while (temp[i] != '\0')
		{
			if (isdigit(temp[i]) == 0) /*0 if not digit*/
			{
				f = 1;
				break;
			}
			i++;
			f = 0;
		}
		if (f == 0)
		{
			if (negative == 1)
				temp = temp + 1;
			newnode->n = atoi(temp);
			if (negative == 1)
				newnode->n *= -1;
			return;
		}
	}
	exit_function(4); /*exit here so don't have to write it twice*/
}

/**
  * add_stack_end - adds an element to the end of the stack (FIFO, queue only)
  * Return: address of new node or NULL if failed
  */
stack_t *add_stack_end(void)
{
	stack_t *temp = NULL;
	stack_t *head = element->head;
	stack_t *traverse;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		return (NULL);
	if (head == NULL)
	{
		free(temp);
		temp = add_stack_init();
	}
	else
	{
		traverse = head;
		while (traverse->next != NULL)
			traverse = traverse->next;
		temp->next = NULL;
		temp->prev = traverse;
		traverse->next = temp;
	}
	return (temp);
}
