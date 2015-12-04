#include <stdio.h>
#include <stdlib.h>



// dynamic mem allocation to a 2D array

int main()
{
	int r = 3;
	int c = 3;

	int i = 0;
	int j = 0;

	int *mat[3];//(int*)malloc(sizeof(int) * 3);

	for(i = 0; i < 3; i++)
	{
		mat[i] = (int*)malloc(sizeof(int)*3);
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			mat[i][j] = j;
		}
	}


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\n", mat[i][j]);
		}
	}


	return 0;
}