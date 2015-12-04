#include <stdio.h>
#include <stdlib.h>

int isValid(int i, int j, int row, int col)
{
	return (i>=0 && i < row) && (j >=0 && j < col);
}

void add(int a[][3], int row, int col)
{
	int i = 0;
	int j = 0;

	int sum = 0;

	int left = 0, right = 0, top = 0, bottom = 0;

	for(i = 0; i <3 ; i++)
	{
		for(j = 0; j<3; j++)
		{
			top = isValid(i+1,j,row,col) ? a[i+1][j] : 0;
			right = isValid(i,j+1,row,col) ? a[i][j+1] : 0;
			bottom = isValid(i-1,j,row,col) ? a[i-1][j] : 0;
			left = isValid(i,j-1,row,col) ? a[i][j-1] : 0;

			sum = top + bottom + left + right;

			a[i][j] = sum;
		}

		sum = 0;
	}	
}

int main()
{
	int a[3][3] = {1,2,3,4,5,6,7,8,9};

	add(a, 3,3);

	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\n", a[i][j]);
		}
	}

	return 0;
}