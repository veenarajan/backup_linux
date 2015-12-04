#include <stdio.h>
#include <stdlib.h>

#include <string.h>

void plusplus(int a[], int n)
{
	int i = 0;
	int sum = 0;
	int carrier = 1;
	for (i = n-1; i >= 0; i--)
	{
		sum = sum + a[i] + carrier;
		carrier = sum/10;
		a[i] = sum%10; 
		//printf("%d",a[i] );
		sum = 0;
	}

	
	if (carrier == 0 )
	{
		 
		 for (i = 0; i < n; i++)
		 {
		 	printf("%d\n", a[i]);
		 }
	}
	else
	{
	
		int new_arr[n+1];
		new_arr[0] = carrier;
		printf("%d\n", new_arr[0]);

		for (i = 1; i < n+1; i++)
		{
			new_arr[i] = a[i-1];
		}

		for (i = 0; i < n+1; i++)
		 {
		 	printf("%d\n", new_arr[i]);
		 }
	}

}

int main()
{
	int a[4] = {8,9,9,9};

	plusplus(a, 4);
}