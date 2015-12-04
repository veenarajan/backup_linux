#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[2] = {10,20};
	//void* m = &a[0];
	printf("%d\n", a[0]);
	//m++;


	//printf("%d\n", (int)sizeof(m));

	int k = 0x12345678;

	char* p =(char*)&k;
	printf("%x\n",*p );
	
	return 0;
}