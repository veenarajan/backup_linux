#include "threads.h"

typedef struct node {
     
     struct TCB_t* semQ; 
	int c;

} semaphore_t;


semaphore_t*  init_sem(int i)
{   printf("\n\n *** In main***\n");
   
    semaphore_t* s=(semaphore_t*)malloc(sizeof(semaphore_t));
    s->c=i;
   struct TCB_t* temp=(struct TCB_t*)malloc(sizeof(struct TCB_t));
   InitQ(temp);
   s->semQ=temp;
   printf("\n\n *** In main***\n");
    return s;
}


/*
 * The P routine decrements the semaphore, and if the value is less than
 * zero then blocks the process 
 */
void P(semaphore_t* sem)
{   
   
    sem->c--;
    if (sem->c < 0)
    {
	
        struct TCB_t* temp=(struct TCB_t*)DelQ(RunQ);
        addQ(sem->semQ,temp->context);
       swapcontext(&temp->context,&(RunQ->lchild)->context);
    } 
       

}

void V(semaphore_t* sem)
{   
   
    sem->c++;
    if (sem->c<= 0) {
	struct TCB_t* temp=(struct TCB_t*)DelQ(sem->semQ);
        addQ(RunQ,temp->context);
    }
  //   swapcontext(&temp->context,&(temp->rchild)->context);
   yield();
    
}



