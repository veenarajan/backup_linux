#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *p = (char*)malloc(sizeof(char)*20);
	char *q = (char*)malloc(sizeof(char)*25);

	//strcpy(p, "amazon");
	//strcpy(q, "usa");

	strcat(p, q);
	printf("%s\n", p);
	return 0;
}