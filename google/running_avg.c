#include <stdio.h>
#include <stdlib.h>

double average(int c[], int n)
{
	int i = 0;
	int sum = 0;
	for(i = 0;i < n ;i++)
	{
		sum+=c[i];
	}
	
	return (double)sum/(double)n;
}

double running_avg(double prev_avg, int n, int new_ele)
{
	double sum = (prev_avg * n) + new_ele;

	return sum / (n+1);
}
int main()
{
	int a[5] = {1,2,3,4,5};
	int ele = 6;

	printf("%lf\n", average(a,5));

	int b[] = {1,2,3,4,5,6};
	printf("%lf\n", average(b,6));

	printf("running_avg %lf\n", running_avg(average(a,5), 5, 6));

	return 0;
}