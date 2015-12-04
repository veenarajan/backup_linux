#include <iostream>
#define maxlen 5
class queue
{
	public:
		int front;
		int rear;
		int a[maxlen];
	public:
		queue(int front, int rear)
		{
			this.front = front;
			this.rear = rear;
		}

		int enqueue(int x)
		{
			if (front ==-1 || rear == -1)
			{
				front = 0;
				rear = 0;
			}
			if (front>=0 && tail+1 == maxlen)
			{
				printf("Queue is full !\n");
				return -1;
			}
			else
			{
				a[tail] = x;
				tail = (tail + 1) % maxlen;
			}

		}	
};


int main(int argc, char const *argv[])
{
	queue q = new queue(-1,-1);

	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);

	return 0;
}