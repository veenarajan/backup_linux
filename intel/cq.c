#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxlen 10
int b[maxlen];

int head = -1;
int tail = -1;

int enqueue(int x)
{
	if ((head == 0 && tail == maxlen-1) || (head > 0 && tail == head -1))
	{
		printf("queue is full... overwriting\n");
	}
	else
	{
		if (head == -1)
		{
			head = 0;
		}

		tail = (tail+1) % maxlen;
		b[tail] = x;
	}

	printf("FINAL !!\n");
	printf("TAIL ::: %d\n", tail);
	printf("HEAD ::: %d\n", head);
	return 0;	
}


int dequeue()
{
	int k;

	if ((head ==-1 || tail == -1) && (head> tail && head == tail -1)) 
	{
		printf("q empty \n");
		return -1;
	}

	else
	{
		k = b[head];
    	head = (head+1) % maxlen;
	}
	return k;
}

int main()
{
	int i;
	int k;
	int j;

	for (i = 0; i < maxlen + 3; i++)
	{
		printf("iiiiiiiii%d\n", i);
		k = enqueue(i);
		printf("kkkkkkk%d\n", k);
	}

	printf("***************\n");
	for (i = 0; i < maxlen + 3; i++)
	{
		printf("iiiiiiiii%d\t", i);
		k = dequeue();
		printf("kkkkkkkkkk%d\n", k);
	}
	return 0;
}

