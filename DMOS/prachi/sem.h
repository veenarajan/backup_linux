#include "threads.h"

typedef struct Semaphore {
     
     struct TCB_t* SemQ; 
	int value;

} Semaphore_t;


Semaphore_t*  CreateSem(int InputValue)
{   
    Semaphore_t* sem=(Semaphore_t*)malloc(sizeof(Semaphore_t));
    sem->value=InputValue;
   struct TCB_t* temp=(struct TCB_t*)malloc(sizeof(struct TCB_t));
   InitQueue(temp);
   sem->SemQ=temp;
    return sem;
}

void P(Semaphore_t* sem)
{   
   
    sem->value--;
    if (sem->value < 0)
    {
	
        struct TCB_t* temp=(struct TCB_t*)DelQueue(&RunQ);
        AddQueue(&sem->SemQ,temp);
       swapcontext(&temp->context,&(RunQ->prev)->context);
    } 
       

}

void V(Semaphore_t* sem)
{   
   
    sem->value++;
    if (sem->value<= 0) {
	struct TCB_t* temp=(struct TCB_t*)DelQueue(&sem->SemQ);
        AddQueue(&RunQ,temp);
    }
   yield();
    
}



