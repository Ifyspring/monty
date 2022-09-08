#include "monty.h"
/**
 *
 *
 *
 */
char **_strtokenize(char *readptr)
{
	char copy_readptr[1024];
	char *delim = "$\n", *token, **argument = NULL;
	int count, index = 0;

	strcpy(copy_readptr, readptr);
	count =  StrCountWord(copy_readptr, delim);
	argument = malloc(sizeof(char *) * (count + 1));
	if (!argument)
		ErrorHandler(3, NULL, 0);
	token = strtok(readptr, delim);
	while (token)
	{
		argument[index] = malloc(sizeof(char) * strlen(token));
		if (!argument[index])
			ErrorHandler(3, NULL, 0);
		strcpy(argument[index], token);
		index++;
		token = strtok(NULL, delim);
	}
	argument[index] = NULL;
	free(readptr);
	return (argument);
}
/**
 *
 *
 */
opcode_t *StrtokenizLineCommand(char *argv, unsigned int line_number)
{
	char *delim = " ", *token = NULL;
	opcode_t *opcode_new = NULL;

	opcode_new =  malloc(sizeof(opcode_t));
	if (!opcode_new)
		ErrorHandler(3, NULL, 0);
	token = strtok(argv, delim);
	opcode_new->opcode_name = token;
	token = strtok(NULL, delim);
	if (!strcmp(opcode_new->opcode_name, "push"))
	{
		if (!token || !isdigit(*token))
		{
			fprintf(stderr, "L%u: usage: print integer\n", line_number);
			exit(EXIT_FAILURE);
		} else
			opcode_new->opcode_value = atoi(token);
	} else
		opcode_new->opcode_value = 0;
	return (opcode_new);
}
/**
 *
 *
 */
int StrCountWord(char *word, char *delim)
{
	char *token = NULL;
	int count = 0;

	token = strtok(word, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	return (count);
}
