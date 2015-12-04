#include<stdio.h>

int main(int argc, char const *argv[])
{
	int a[] = {5,9,7,2,1,8};
	int i=0, j=0;
	int temp;
	for (i = 0; i < 3; i++)
	{
		for (j = i; j < 6; j++)
		{
			if (a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		//printf("a[j]%d\n", a[j]);
		}
	}

	for (i = 5; i > 2; i--)
	{
		printf("a[i]%d\n", a[i]);
	}
	return 0;
}