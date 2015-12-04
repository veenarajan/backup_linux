#include<stdio.h>
#include<stdlib.h>
#include "q.h"
#define CONTEXT_SIZE 8192
struct TCB_t* RunQ;



int c_gl=0;

void start_thread(void (*function)(void),struct TCB_t* temp12)
{ 
   char st1[8192];
   char* stack = (char*)malloc(8192);
//     allocate a stack (via malloc) of a certain size (choose 8192)
     
       struct TCB_t* tcb=(struct TCB_t*)malloc(sizeof(struct TCB_t));
    
	init_TCB (tcb,function,stack,8192);
	printf("\n\n *** add Q***\n");
  
     addQ(RunQ,tcb->context);
   printf("\n\n *** add Q***\n");     //call addQ to add this TCB into the “RunQ" which is a global header pointer
 
	
  
}

void run()
{  
    ucontext_t parent,pa;     // get a place to store the main context, for faking
       int c=getcontext(&parent);   // magic sauce
    printf("context %d",c);
   

    struct TCB_t* temp=(struct TCB_t*)malloc(sizeof(struct TCB_t));
    if(RunQ->lchild!=RunQ)
    { 
     temp=RunQ->lchild;

      swapcontext(&parent,&temp->context);  // start the first thread
    }
    
    printf("\n in run \n");
    
}
void yield() // similar to run
{
  
  struct TCB_t* temp=(struct TCB_t*)malloc(sizeof(struct TCB_t));
  temp=RunQ->lchild;
  RotateQ(RunQ);
  
  swapcontext(&(RunQ->lchild->lchild)->context,&(RunQ->lchild)->context);
     
}
