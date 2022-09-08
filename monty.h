#ifndef MONTY_H
#define MONTY_H
/* header files */
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define READSIZE 1024
#define EXIT exit(EXIT_FAILURE);
extern int stack_value;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 *
 *
 */
typedef struct opcode
{
	char *opcode_name;
	int opcode_value;
} opcode_t;
/* function declaration */
void ErrorHandler(int, char *, int);
char **_strtokenize(char *);
int StrCountWord(char *, char *);
opcode_t *StrtokenizLineCommand(char *, unsigned int);
void Func_push(stack_t **, unsigned int);
void Func_pall(stack_t **, unsigned int);
void Func_pop(stack_t **, unsigned int);
void Func_pint(stack_t **, unsigned int);
void Func_swap(stack_t **, unsigned int);
void Func_add(stack_t **, unsigned int);
void Func_nop(stack_t **, unsigned int);
void Func_sub(stack_t **, unsigned int);
void Func_div(stack_t **, unsigned int);
void Func_mul(stack_t **, unsigned int);
void Func_mod(stack_t **, unsigned int);
void Func_pchar(stack_t **, unsigned int);
void Func_pstr(stack_t **, unsigned int);
void Func_rotl(stack_t **, unsigned int);
void free_stack(stack_t **);
int CountStack(stack_t **);
#endif
