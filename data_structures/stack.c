#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack {
	int   ind;
	const int size;
	int  *array;
} stack;


stack* defaultstack(const int size)
{
	stack* s = malloc(sizeof(stack));
	if (s == NULL) 
	{
		fprintf(stderr, "Error: malloc of stack failed\n");
		return NULL;
	} 

	*(int*)&s->size = size;
	s->array = malloc(s->size * sizeof(int));
	s->ind = -1;

	if (s->array == NULL) 
	{
		fprintf(stderr, "Error: malloc of array failed\n");
		return NULL;
	}

	return s;
}

int push(stack* s, int val)
{
	if (s->ind == s->size - 1)
	{
		fprintf(stderr, "Error: stack is full\n");
		return 1;
	}

	s->array[++s->ind] = val;
	return 0;
}

int pop(stack* s)
{
	if (s->ind == -1)
	{
		fprintf(stderr, "Error: stack is empty\n");
		return INT_MIN;
	}
	return s->array[s->ind--];
}

int peek(stack* s)
{
	if (s->ind == -1)
	{
		fprintf(stderr, "Error: stack is empty\n");
		return INT_MIN;
	}
	return s->array[s->ind];
}

