#include <stdio.h>
// Same as "void print(int **arr, int m, int n)"
void print(int *arr, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			printf("%d ", *((arr+i*n) + j)  );
}

// standard 
void print1(int arr[][3], int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
}


// again standard
void print2(int (*arr)[3], int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
}

void print3(int (*arr)[][3], int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			printf("%d ", (*arr)[i][j]);
}

void print4(int ** arr, int m, int n)
{
	int i, j;
	int * temp[m];
	
	for (i = 0;i<m;i++)
	temp[i] = (int*)arr + n*i;

	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		printf("%d ", temp[i][j]);																																																																						
}

void print5(int *arr[3], int m, int n)
{
	int i, j;
	int * temp[m];
	
	for (i = 0;i<m;i++)
	temp[i] = (int*)arr + n*i;

	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		printf("%d ", temp[i][j]);
}


int main()
{
	int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int m = 3;
	int n = 3;
	printf("\nsize of arr: %d",(int)sizeof(*arr+1));
	printf("\narray element: %d",*arr[1]);
	printf("%d\n", *(*(arr+0) + 2) );

//	print5(arr, m, n);
	return 0;
}

