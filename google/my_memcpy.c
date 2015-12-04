#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void my_memcoy(void* desti, void* srcs, int number)
{
	int i = 0;
	char* src = (char*)srcs;
	char* dest = (char*)desti;
	
	char* temp = (char*)malloc(sizeof(char) * number);

	for (i = 0; i < number; ++i)
	{
		temp[i] = src[i];
	}

	for (i = 0; i < number; ++i)
	{
		dest[i] = temp[i];
	}
	
}
int main()
{
	char *s = "veena";
	char *d = (char*)malloc(sizeof(char) * strlen(s));

	my_memcoy((void*)d, (void*)s, (int)strlen(s));


	printf("%s\n", d);
	printf("%d\n", '0');
	printf("%d\n", '1');
	//printf("%d\n", "20");
	int number = 115;
	int temp;
	while (number>0) 
	{ 
		temp =number%10;
		printf("%d\n", temp); 
		number/=10; 
	} 
	return 0;
}
