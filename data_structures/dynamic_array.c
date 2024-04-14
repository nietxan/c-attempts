#include <stdio.h>
#include <stdlib.h>

#define ever  (;;)
#define size  sizeof(int)


int main()
{
	int    len;
	int*   arr;
	int*   curr;

	int    decl = 0;
	char*  cmd  = malloc(8 * sizeof(char));

	for ever
	{
		printf("-> ");

		scanf("%s", cmd);

		switch (*cmd) 
		{
			case 'n':
				printf("len: ");
				scanf("%d", &len);

				arr = malloc(size * len);		
				curr = arr;
				decl = 1;
				break;
			case 'a':
				if (!decl)
				{
					puts("array is not declared");
					exit(1);
				}

				if (arr - curr == len)
				{
					puts("array is full");
					exit(1);
				}

				printf("input: ");
				scanf("%d", curr);
				++curr;
				break;
			case 'i':
				if (!decl)
				{
					puts("array is not declared");
					exit(1);
				}

				for (int* i = arr; i != (arr + len); ++i)
				{
					printf("%d ", *i);
				}
				putchar('\n');
				break;
			case 'q':
				if (decl)
					free(arr);
				free(cmd);
				exit(0);
			default:
				break;
		}
		
	}
}

