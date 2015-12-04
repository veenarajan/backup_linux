#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void find_power_set(int a[], int n)
{
	int i = 0;
	int count = 0;
	double size = pow(2.0, n); 
	while(count< (int)size)
	{
		printf("count :: %d\n",count );
		
		for (i = 0; i < n; i++)
		{
			if (count & 1<<i)
			{
				printf("%d",a[i]);
			}
		}
		
		count++;
		

		printf("\n");
	}
}
int main(int argc, char const *argv[])
{
	int a[3] = {1,2,3};
	find_power_set(a, (int)(sizeof(a)/sizeof(a[0])));
	return 0;
}