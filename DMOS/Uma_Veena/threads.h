#include "q.h"

void start_thread(void (*function)(void))
{
    TCB_t *tcb;
    int stack_size = 8192;
    void *stackP;
    stackP = malloc(stack_size);
    tcb = (TCB_t *) malloc (sizeof(struct TCB_t));
    init_TCB(tcb, function, stackP, stack_size);
    AddQ(&RunQ, tcb);
}

void run()
{
    ucontext_t parent;     			   // get a place to store the main context
    getcontext(&parent);   			  // initializes the structure to the currently active context.
    swapcontext(&parent, &(RunQ->context));  	  // start the first thread
}

void yield()
{
    ucontext_t current; 
    getcontext(&current);
    RunQ->context = current;
    RotateQ(&RunQ);
    swapcontext(&current, &(RunQ->context));
    
    //The swapcontext() function saves the current context in the structure pointed to by current,
    //and then activates the context pointed to by RunQ->context
}
