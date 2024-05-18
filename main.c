#include "data_structures/linkedlist.c"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	node* head;

	head = malloc(sizeof(node));
	if (!head) 
	{
		perror("malloc failed");
		return 1;
	}
	fill(head, 12);
	
	print(head);

	return 0;
}

