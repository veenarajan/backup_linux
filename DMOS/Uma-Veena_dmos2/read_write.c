/*
@Name: Uma Satish Kulkarni (1207684864)
@ Veena Sunder Rajan (1207769429)
Distributed Multiprocessor Operating systems - CSE 531
Project 4
Title: To implement Readers and Writers.
*/

#include "sem.h"

int global;
sem_t *mutex;
sem_t *wsem, *rsem;
int rc = 0, wwc = 0, wc = 0, rwc = 0;
int count = 0;


void reader();
void writer();

int main()
{
	initQueue(RunQ);
	mutex = init_sem(1);;
	rsem = init_sem(0);
	wsem = init_sem(0);

	// 3 reader and 2 writer threads are created
	start_thread(reader);
	start_thread(reader);
	start_thread(reader);
	start_thread(reader);
	start_thread(reader);
	start_thread(writer);
	start_thread(writer);

	run();
	return 0;
}

void reader_entry(int reader_ID)
{

	P(mutex);
	if ((wwc > 0)||(wc > 0))
	{
		printf("[reader: %d] waiting...!!!\n", reader_ID);
		rwc++;
		V(mutex);
		P(rsem);
		rwc--;
	}
	rc++;
	printf("Reader: %d in entry section\n",reader_ID);

	if (rwc > 0)
		V(rsem);
	else
		V(mutex);
}

void reader_exit(int reader_ID)
{
	printf("Reader: %d in exit section\n",reader_ID);
	P(mutex);
	rc--;
	if ((rc == 0)&&(wwc > 0))
		V(wsem);
	else
		V(mutex);
}

void writer_entry(int writer_ID)
{
	P(mutex);
	if ((rc > 0)||(wc > 0))
	{
		printf("	[writer: %d] writer waiting..!!!!\n", writer_ID);
		wwc++;
		V(mutex);
		P(wsem);
		wwc--;
	}
	printf("	[Writer: %d] in entry section \n",writer_ID);
	wc++;
	V(mutex);
}

void writer_exit(int writer_ID)
{
	printf("	Writer: %d in exit section\n",writer_ID);
	P(mutex);
	wc--;
	if (rwc > 0)
		V(rsem);
	else if (wwc > 0)
		V(wsem);
	else
		V(mutex);
}

void reader()
{
	int reader_ID = 0;
	P(mutex);
	reader_ID = count++;
	V(mutex);

	while(1)
	{
		reader_entry(reader_ID);
		printf("Reader: %d Reading....... \n",reader_ID);
		sleep(1);
		reader_exit(reader_ID);
	}

}
void writer()
{
	int writer_ID = 0;
	P(mutex);
	writer_ID = count++;
	V(mutex);

	while(1)
	{
		writer_entry(writer_ID);
		printf("\nWriter: %d writing.........\n",writer_ID);
		sleep(1);
		writer_exit(writer_ID);
	}
}
