#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a = 5;
	int b = 10;
	int count1;
	int count2;
	
	while(a!=0 && b!=0)
	{
		count1++;
		a = a>>1;
		b = b>>1;
	}
	if (b>0)
	{
		printf("b is greater\n");
	}
	else
		printf("a is greater\n");
	printf("%d\n", count1);

	return 0;
}
