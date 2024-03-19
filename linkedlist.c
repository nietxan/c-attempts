#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

typedef struct node {
	int val;
	struct node* next;
} node;


/* pass only empty list */
void fill_list(node* head, int n)
{
	int    i;
	node*  cur;

	cur  = malloc(sizeof(node));

	head->next = cur;
	head->val  = -1;

	for (i = 1; i <= n; ++i)
	{
		cur->next = malloc(sizeof(node));
		cur->val = i;
		cur = cur->next;
	}
}

int print_list(node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");

	return 0;
}

node* reverse(node* head, int list_size)
{
	stack*  s;
	node*   cur;

	s = new_stack(list_size);

	while (head != NULL)
	{
		push(s, head->val);
		head = head->next;
	}

	head = malloc(sizeof(node));
	cur = malloc(sizeof(node));

	head->next = cur;
	head->val  = -1;

	while (s->top != -1)
	{
		cur->next = malloc(sizeof(node));
		cur = cur->next;
		cur->val = pop(s);
	}
	
	return head->next;
}

