#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>

void palindrome(char* str, int size)
{
	int i = 0;
	int count=0;
	char* st = "rA";
	if(size==0)
	{
		return;
	}
	for(i=0; i < size/2; i++)
	{
		printf("%d\t", str[i]);
		printf("%d\n", str[size-1-i]);
		printf("%c\n", str[size-1-i]);
		printf("%d\n", strcasecmp(str, st));
		printf("%s\n", strerror(errno));
	}

	if(count == size/2)
	{
		printf("%s","palindrome");
	}

}

int main()
{
	char s[] = "RADar";

	palindrome(s, (int)strlen(s));
	return 0;
}