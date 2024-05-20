#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack {
	int   top;
	const int size;
	int*  array;
} stack;

stack* defaultstack(int size)
{
	stack stacksize = {.size = size};

	stack* s = malloc(sizeof(stack));
	if (!s) 
	{
		perror("malloc failed");
		return NULL;
	}
	memcpy(s, &stacksize, sizeof(stacksize));

	s->array = malloc(sizeof(int));
	if (!s->array) 
	{
		perror("malloc failed");
		return NULL;
	}

	return s;
}

void push(stack* s, int val)
{
	if (s->top == s->size - 1)
	{
		perror("stack is full");
		return;
	}

	s->array[++s->top] = val;
}

int pop(stack* s)
{
	if (s->top == -1)
	{
		perror("stack is empty");
		return INT_MIN;
	}
	return s->array[s->top--];
}

int peek(stack* s)
{
	if (s->top == -1)
	{
		perror("stack is empty");
		return INT_MIN;
	}
	return s->array[s->top];
}

