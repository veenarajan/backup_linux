#include "q.h"

TCB_t *RunQ;

void start_thread(void (*function)(void))
{
    
     TCB_t *tcb = NewItem();
     InitQueue(tcb);
     int *stackP= (int *)malloc(8192 * sizeof(int));
     init_TCB(tcb, function, stackP, 8192);
     AddQueue(&RunQ, tcb);
}

void yield()
{
   RotateQ(&RunQ);
   swapcontext(&(RunQ->prev->context), &RunQ->context);
}

void run()
{
    ucontext_t parent;
    getcontext(&parent);
    swapcontext(&parent, &RunQ->context);
}

