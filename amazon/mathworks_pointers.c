#include <stdio.h>
#include <stdlib.h>

int main()
{
	//int x;
	//int y;

	//printf("%p\n", &x);
	//printf("%p\n", &y);

	int *a;
	int *b;

	printf("%p\n", &a);
	printf("%p\n", &b);
	a = &b;
	b = &a;

	printf("%p\n", &a);
	printf("%p\n", &b);

	return 0;
}