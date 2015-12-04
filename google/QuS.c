#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

stack *s1;
stack *s2;

int enqueue(int data)
{
	return push(s1, data);
}

int dequeue()
{
	if (!empty(s2))
	{
		return pop(s2);

	}
	while(!empty(s1))
			push(s2, pop(s1));
	return pop(s2);
	
}

int main(int argc, char const *argv[])
{
	s1 = (stack*)malloc(sizeof(stack));
	s1->a = (int *)malloc(max * sizeof(int));

	s1->top = -1;

	s2 = (stack*)malloc(sizeof(stack));
	s2->a = (int *)malloc(max * sizeof(int));

	s2->top = -1;

	printf("%d\n", enqueue(10));
	printf("%d\n", enqueue(20));

	printf("%d\n", dequeue());
	printf("%d\n", enqueue(50));
	printf("%d\n", dequeue());
	
	return 0;
}