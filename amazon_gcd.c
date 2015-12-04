#include <stdio.h>
#include <stdlib.h>

int cal_gcd(int a,int b)
{
	while(a!=b)
	{
		if(a>b)
			a-=b;
		else
			b-=a;
	}

	return a;	
}

int gcd(int a[], int n)
{
	if(a == NULL)
	{
		return 0;
	}
	
	if(n == 1)
	{
		
		return a[0];
	}

	if(n==2)
	{
		return cal_gcd(a[0], a[1]);
	}

	int mid = n/2;

	return cal_gcd(gcd(&a[mid-1],mid) , gcd(&a[mid], n-mid));
}


int gcd_i(int a[], int n)
{
	int i = 0;
	int result = a[0];
	for (i = 1; i < n; i++)
	{
		result = cal_gcd(result, a[i]);
	}

	return result;
}
int main()
{
	int a[] = {2,6,12};

	int n = (int)(sizeof(a)/sizeof(a[0]));

	//printf("%d\n", cal_gcd(10,3));

	//printf("%d\n", cal_gcd(4,2));
	printf("%d\n", gcd(a,n));
	return 0;
}