#include <stdio.h>
#include <stdlib.h>
#include <string.h>
union U
{
	int a;
	float f;
	char c[20];
};


int main(int argc, char const *argv[])
{
	union U union_test;
	
	
	strcpy(union_test.c, "veena sunder rajan");
	union_test.a = 8;

	printf("%d\n", union_test.a);
	printf("%s\n", union_test.c);
	return 0;
}

