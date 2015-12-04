x#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x=10;
	int *p = &x;

	int i;
	int* a[10];

	for (i = 0; i < 10; i++)
	{
		a[i] = (int*)malloc(sizeof(int));

		*(a[i]) = i;
	}

	for (i = 0; i < 10; ++i)
	{
		printf("%d\n", *(a[i]));
	}

	printf("%p\n", a[0]);
	printf("%p\n", a[1]);

	return 0;
}