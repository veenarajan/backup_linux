#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[9] = {1,4,5,6,8,9,10};

	int sum =0;
	int i;
	int check = 1;
	for(i =1;i<11;i++)
	{
		sum+=i;
		check*=i;
	}


	printf("%d\n", sum);
	for (i = 0; i < 7; i++)
	{
		sum-=a[i];
		check = check/a[i];
	}


	if (sum!=0)
	{
		printf("%d\n", sum);
	}

	if (check!=1)
	{
		printf("%d\n", check);
	}

	int max= a[0];
	int min = a[0];

	for (i = 0; i < 7; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min  = a[i];
		}
	}

	printf("max :%d\n", max);
	printf("min %d\n", min);
	int b = max - min;
	printf("%d\n", b);

	int *c = (int*)calloc(b, sizeof(int));

	for (i = 0; i < 7; i++)
	 {
	 	printf("%d\n", a[i]-min);
	 	c[a[i]-min] = 1;
	 	//printf("%d\n", c[i]);
	 } 

	 for (i = 0; i < 7; i++)
	 {
	 	if (!(c[i]))
	 	{
	 		printf("missing %d\n", i);
	 	}
	 }


	return 0;
}