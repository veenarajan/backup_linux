# include "threads.h"

//Semaphore data structure
typedef struct my_semaphore
{
	int count;
	TCB_t *queue;
}sem_t;

//Initializes the semaphore with the specified value
sem_t* init_sem(int x)
{
	sem_t *sem_head;
	sem_head = (sem_t *)malloc (sizeof(struct my_semaphore));

	initQueue(sem_head->queue);
	sem_head->count = x;
	return sem_head;
}

/*The P routine decrements the semaphore,
and if the value is less than zero then blocks the process in the queue associated with the semaphore.*/
void P(sem_t *sem)
{
	TCB_t *tcb_block;
	sem->count--;
	//printf("P Operation\n");
	if (sem->count < 0)
	{
		//block
		printf("Thread blocked\n");
		tcb_block = (TCB_t *)DelQueue(&RunQ);
		AddQueue(&(sem->queue), tcb_block);
		swapcontext(&(tcb_block->context), &(RunQ->context));
	}
}

/*The V routine increments the semaphore,
and if the value is 0 or negative, then takes a PCB out of the semaphore queue and puts it into the run queue.*/
void V(sem_t *sem)
{
	sem->count++;
	//printf("V operation\n");
	if(sem->count <= 0)
	{
		printf("Thread woken up\n");
		AddQueue(&RunQ,DelQueue(&(sem->queue)));
	}
	yield();
}