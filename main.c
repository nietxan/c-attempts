#include "data_structures/linkedlist.c"


int main(int argc, char* argv[])
{
	node* head;

	fill(head, 100);
	print(head);
	
	head = reverse(head);
	print(head);

	free(head);

	return 0;
}

