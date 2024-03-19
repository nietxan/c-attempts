#include "linkedlist.c"
#include <stdlib.h>

#define SIZE 15

int main()
{
	node* head = malloc(sizeof(node));
	fill_list(head, SIZE);
	print_list(head);

	node* reversed = malloc(sizeof(node));
	reverse(head, SIZE);
	print_list(reversed);

	return 0;
}
