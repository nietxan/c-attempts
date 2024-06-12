#include "data_structures/linkedlist.c"
#include <stdio.h>
#include <stdlib.h>

void printlist(node* head)
{
	if (head == NULL)
	{
		printf("\n");
		return;
	}

	printf("%d ", head->val);
	printlist(head->next);
}

int main(int argc, char* argv[])
{
	/* LINKED LIST REVERSE */

	node* head;

	head = malloc(sizeof(node));
	listconst(head, 10);
	printlist(head);

	head = reverse(head);
	printlist(head);

	listdest(head);
}

