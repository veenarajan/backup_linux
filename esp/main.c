#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "my_queue.h"

int global_count = 0;

struct Queue* bufferqueue;

struct message* get_message()
{
	struct message* newmessage = (struct message*)malloc(sizeof(struct message));
	newmessage->data = (char*)malloc(sizeof(char)*100);
	newmessage->sender_id = 1;
	newmessage->receiver_id = 1;
	newmessage->number = global_count++;
	return newmessage;
}

void *sender_func()
{
	struct message* newmessage = get_message();
	enQueue(bufferqueue, newmessage);
}

void *receiver_func()
{
	struct message newmessage = deQueue(bufferqueue);
	printf("%d\n", newmessage.sender_id);
	printf("%d\n", newmessage.receiver_id);
	printf("%s\n", newmessage.data);
	printf("%d\n", newmessage.number);
}
int main(int argc, char const *argv[])
{
	bufferqueue = createQueue(5);
	pthread_t sender;
	pthread_t receiver;

	pthread_create(&sender, NULL, sender_func, NULL);
	usleep(10000);
	pthread_create(&receiver, NULL, receiver_func, NULL);

	pthread_join(sender, NULL);
	pthread_join(receiver, NULL);
	return 0;
}