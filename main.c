#include "data_structures/linkedlist.c"
#include <assert.h>
#include <limits.h>
#include <stdio.h>

#define STACK_SIZE 10

int main(int argc, char* argv[])
{
	/*  TESTS */

	int i;
	int val;
	stack* s;

	s = defaultstack(STACK_SIZE);
	
	assert(s != NULL);
	assert(s->array != NULL);
	assert(s->size == STACK_SIZE);
	assert(s->ind == -1);

	assert(pop(s) == INT_MIN);
	assert(peek(s) == INT_MIN);

	for (i = 0; i < STACK_SIZE; push(s, ++i));
	
	for (i = 0; i < s->size; ++i)
	{	
		if ((val = pop(s)) == INT_MIN) 
		{
			exit(1);
		}
		printf("%d ", val);
	}

	return 0;
}

