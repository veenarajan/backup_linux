#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int first;
	int second;
	int third;

	int i;
	int j;

	int a[9] = {1,2,3,4,5,6,7,8,9};
	first = second = third = a[0];
	for (i = 1; i < 9; i++)
	{
		if (first < a[i])
		{
			third = second;
			second = first;
			first = a[i];
		}
		else if (second < a[i])
		{
			third = second;
			second = a[i];	
		}
		else if (third < a[i])
		{
			third = a[i];
		}	
	}

	printf("first :: %d\n",first );
	printf("second :: %d\n",second );
	printf("third :: %d\n",third );
	return 0;
}

