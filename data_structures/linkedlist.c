#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"


typedef struct node {
	int val;
	struct node* next;
} node;

void freelist(node* head)
{
	node* temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;	
	}
}

void fill(node* head, int n)
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

int print(node* head)
{
	while (head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");

	return 0;
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

void stacktolist(stack* s, node* head)
{
	int val;

	while ((val = pop(s)) != INT_MIN) 
	{
		head->val = val;
		head->next = malloc(sizeof(node));
		head = head->next;
	}
}

void listtostack(node* head, stack* s)
{
	while (head != NULL)
	{
		push(s, head->val);
		head = head->next;
	}
}

node* reverse(node* head)
{
	stack* s;
	node* rev;

	rev = malloc(sizeof(node));
	s = defaultstack(sizeoflist(head));

	listtostack(head, s);
	stacktolist(s, rev);

	freelist(head);
	free(s);

	return rev;
}



