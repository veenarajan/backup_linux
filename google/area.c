#include <stdio.h>
#include <stdlib.h>

int area(int a[3][3], int m, int n)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < 3; i++)
	{
		if(a[i][j] == 1)
		{
			count++;
			while(j<n && a[i][j+1] == 1)
			{
				printf("ffmkdkmfkdmk\n");
				count++;
				j++;
			}
			j=0;
		}
	}

	return count;

}
int main()
{
	int m = 3;
	int n = 3;
	int a[3][3] = {{1,0,1},{1,0,0},{1,0,0}};

	int l  = area(a, m, n);
	printf("%d\n", l);
	return 0;
}