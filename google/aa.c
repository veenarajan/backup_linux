#include <stdio.h>
#include <stdlib.h>

void sum(int **matrix,int rows, int cols)
{
	int sum = 0;
	int i = 0;
	int j = 0;
	int col[3] = {0};
	int row[3] = {0};

	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			if(i > 0 && i < rows && j> 0 && j< cols)
			{
				sum += matrix[i-1][j] + matrix[i][j-1] + matrix[i+1][j] + matrix[i][j+1];
				matrix[i][j] = sum;
			}
			else
			{
				if (i == 0)
				{
					
				}
			}
		}
	}

}