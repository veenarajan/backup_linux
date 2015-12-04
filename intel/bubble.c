#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int a[10] = {9,8,7,6,5,4,3,2,1,10};
	int n = sizeof(a)/sizeof(a[0]);
	int i;
	int j;
	int temp;
	
	for (i = 0; i < n-1; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;	
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d\n",a[i] );
	}
	return 0;
}