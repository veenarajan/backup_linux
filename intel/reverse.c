#include<stdio.h>
#include<stdlib.h>
void reverse(int a[], int start,int n)
{
	int i=start;
	int temp;
	int d = (start + n)/2;
	for (i = start; i < d; i++)
	{
		temp = a[i];
		a[i] = a[d -i-1];
		a[d-i-1] = temp;
	}
}
int main(int argc, char const *argv[])
{
	int a[10]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int *b;
	//int *b = (int *)malloc(sizeof(int) * 10);
	
	int n = 10;
	int k = 3;

	int i=0;
	int temp;

	for (i = 0; i < n; i++)
	{
		printf("%d", i[a]);
	}
	printf("\n");
	
	reverse(a, 0, 3);
	

	for (i = 0; i < n; i++)
	{
		printf("%d", i[a]);
	}
	printf("\n");
	

	reverse(a, 3, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", i[a]);
	}
	printf("\n");

	reverse(a, 0, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", i[a]);
	}


	return 0;
}