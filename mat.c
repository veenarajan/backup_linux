#include <stdio.h>
#include <stdlib.h>

void print(int **a)
{
	//printf("%d",a[0][0]);

	printf("%d\n", *(*(a +1)+1));
}

int main()
{
	int a[3][3] = {{1, 2, 3} , {4, 5, 6}, {7, 8, 9}};

	print((int**)a); 
	return 0;
}