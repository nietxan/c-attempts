#include <stdio.h>
#include <stdlib.h>
#include "stack.c"


typedef struct node {
	int val;
	struct node* next;
} node;

void fillempty(node* head, int n)
{
	node* ptr = head;

	for (int i = 1; i < n; ++i)
	{
		ptr->val = i;
		ptr->next = malloc(sizeof(node));
		ptr = ptr->next;
	}
}

void fillnotempty(node* head, int n)
{
	node* ptr = head;

	for (int i = 1; i < n; ++i)
	{
		ptr->val = i;
		if (ptr->next == NULL) 
		{
			ptr->next = malloc(sizeof(node));
		}
		ptr = ptr->next;
	}

}

/* pass only  */
void fill(node* head, int n)
{
	if (head == NULL)
	{
		head = malloc(sizeof(node));
		if (!head)
		{
			perror("malloc failed");
			return;
		}
		fillempty(head, n);
	}

	fillnotempty(head, n);
}

int print(node* node)
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

