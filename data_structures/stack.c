#include <limits.h>
#include <stdlib.h>


typedef struct stack {
	int   top;	
	int   size;
	int*  array;
} stack;

stack* new_stack(int size)
{
	stack* s = malloc(sizeof(stack));
	s->size  = size;
	s->top   = -1;
	s->array = malloc(s->size * sizeof(int));

	return s;
}

void push(stack* s, int val)
{
	if (s->top == s->size - 1)
	{
		return;
	}

	s->array[++s->top] = val;
}

int pop(stack* s)
{
	if (s->top == -1)
	{
		return INT_MIN;
	}
	return s->array[s->top--];
}

int peek(stack* s)
{
	if (s->top == -1)
	{
		return INT_MIN;
	}
	return s->array[s->top];
}

