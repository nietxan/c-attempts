#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack {
	int   ind;
	const int size;
	int*  array;
} stack;

stack* defaultstack(int size)
{
	stack stacksize = {.size = size};

	stack* s = malloc(sizeof(stack));
	if (s == NULL) 
	{
		perror("malloc of stack failed\n");
		return NULL;
	} 

	memcpy(s, &stacksize, sizeof(stacksize));

	s->array = malloc(sizeof(int));
	if (s->array == NULL) 
	{
		perror("malloc of array failed\n");
		return NULL;
	}

	return s;
}

int push(stack* s, int val)
{
	if (s->ind == s->size)
	{
		perror("stack is full");
		return 1;
	}

	s->array[++s->ind] = val;
	return 0;
}

int pop(stack* s)
{
	if (s->ind == 0)
	{
		perror("stack is empty");
		return INT_MIN;
	}
	return s->array[s->ind--];
}

int peek(stack* s)
{
	if (s->ind == 0)
	{
		perror("stack is empty");
		return INT_MIN;
	}
	return s->array[s->ind];
}

