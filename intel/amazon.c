#include <stdio.h>

void check(int a[], int n)
{

	int l = sizeof(a);///sizeof(a[0]);
	printf("%d\n",l );
	int i,j;
	int f = 0;
	int k;
	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (a[i]==a[j])
			{
				k = a[i];
				f= 1;
				break;
			}
		}

		if (f)
		{
			printf("rep ele %d\n", k);
			f=0;
		}
	}
}
void check1(int a[], int n)
{
	int b[100] = {0};
	int i;
	for(i = 0;i<n;i++)
	{
		b[a[i]]++;
	}

	int j = 0;
	while(j<100){

	if(b[j]!=0)
	{
		printf("rep element %d times %d\n",j, b[j]);
		
	}
	j++;
}
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5,4};
	int n = sizeof(a)/sizeof(a[0]);
    printf("%d\n",(int) sizeof(a));
	///sizeof(a[0]);
	check(a, n);
	check1(a, n);
	return 0;
}