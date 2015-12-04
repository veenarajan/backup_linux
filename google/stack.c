#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct stack
{	
	int *a;
	int top;
	
}stack;


int push(stack *s, int data)
{
	if (s->top == max)
	{
		printf("stack is full \n");
		return -1;
	}
	s->top++;
	s->a[s->top] = data;

	return 0;
}

int pop(stack *s)
{
	if (s->top == -1)
	{
		printf("stack is empty\n");
		return -1;
	}

	int k = s->a[s->top];
	s->top--;
	return k;
}

int peek(stack *s)
{
	return s->a[s->top];
}


int empty(stack *s)
{
	return s->top == -1;
}

/*int main(int argc, char const *argv[])
{
	stack *s = (stack*)malloc(sizeof(stack));
	s->a = (int *)malloc(max * sizeof(int));

	s->top = -1;
	int k;
	int i;
	for (i = 0; i < 15; ++i)
	{
		k = push(s,i*2);
	}

	for (i = 0; i < 15; ++i)
	{
		printf("%d\n", pop(s));
	}

	return 0;
}*/