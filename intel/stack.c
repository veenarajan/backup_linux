#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxlen 10
int a[maxlen];
int top = -1;

int push(int x)
{
	if (top == -1)
	{
		top = 0;
	}

	if (top == maxlen)
	{
		printf("stack is full\n");
		return -1;
	}
	else
	     a[top++] = x;

	return 0;

}

int pop()
{
	if (top == -1)
	{
		printf("stack is empty\n");
		return -1;
	}
	
	top--;
	
	return a[top];
}

int main(int argc, char const *argv[])
{
	int k;
	int j;
	int i;

	for ( i = 0; i < maxlen+3; i++)
	{
			k = push(i);
			printf("%d\n", k);
	}	

	
    for ( i = 0; i < maxlen+3; i++)
	{
			k = pop();
			printf("%d\n", k);
	}
	return 0;
}