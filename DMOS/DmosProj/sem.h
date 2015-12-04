#include "threads.h"

typedef struct node {
     
     struct TCB_t* semQ; 
	int value;

} semaphore_t;


semaphore_t*  init_sem(int InputValue)
{  
    semaphore_t* s=(semaphore_t*)malloc(sizeof(semaphore_t));
    s->value=InputValue;
   struct TCB_t* temp=(struct TCB_t*)malloc(sizeof(struct TCB_t));
   InitQ(temp);
   s->semQ=temp;
    return s;
}

void P(semaphore_t* sem)
{   
    sem->value--;
    if (sem->value < 0)
    {
	
        struct TCB_t* temp=(struct TCB_t*)DelQ(RunQ);
        addQ(sem->semQ,temp->context);
       swapcontext(&temp->context,&(RunQ->lchild)->context);
    }
}

void V(semaphore_t* sem)
{   
   
    sem->value++;
    if (sem->value <= 0) {
	struct TCB_t* temp=(struct TCB_t*)DelQ(sem->semQ);
        addQ(RunQ,temp->context);
    }

   yield();
    
}



