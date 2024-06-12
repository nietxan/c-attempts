#include <stdio.h>
#include <stdlib.h>
#include "stack.c"


typedef struct node {
	int val;
	struct node* next;
} node;


void listconst(node* head, int n)
{
	if (head == NULL)
	{
		head = malloc(sizeof(node));
		if (!head)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return;
		}
	}

	for (int i = 1; i < n; ++i)
	{
		head->val = i;
		if (head->next == NULL) 
		{
			head->next = malloc(sizeof(node));
			if (!head->next)
			{
				fprintf(stderr, "Error: malloc failed\n");
				return;
			}
		}
		head = head->next;
	}

	head->val = n;
}

void listdest(node* head)
{
	node* temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;	
	}
}

int sizeoflist(node* head)
{
	int size;

	while (head != NULL)
	{
		head = head->next;
		size++;
	}

	return size;
}

int listtostack(node* head, stack* s)
{
	if (head == NULL)
	{
		fprintf(stderr, "Error: empty list\n");
		return 1;
	}

	while (head != NULL)
	{
		if (push(s, head->val))
		{
			fprintf(stderr, "Error: push() in listtostack failed\n");
			return 1;
		}

		head = head->next;
	}

	return 0;
}

int stacktolist(stack* s, node* head)
{
	if (head == NULL)
	{
		head = malloc(sizeof(node));
	}

	for (int i = 0; i < s->size - 1; ++i)
	{
		head->val = pop(s); 	

		head->next = malloc(sizeof(node));
		if (head->next == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return 1;
		}

		head = head->next;
	}

	head->val = pop(s);

	return 0;
}

node* reverse(node* head)
{
	int size;
	stack* s;
	node* rev;

	size = sizeoflist(head);
	s = stackconst(size);
	rev = malloc(sizeof(node));

	if (listtostack(head, s))
	{
		fprintf(stderr, "Error: listtostack failed\n");
		return NULL;
	}

	if (stacktolist(s, rev))
	{
		fprintf(stderr, "Error: stacktolist failed\n");
		return NULL;
	}

	listdest(head);
	stackdest(s);

	return rev;
}


