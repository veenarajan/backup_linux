#include <ucontext.h>

struct TCB_t
{
ucontext_t context;
struct TCB_t* lchild;
struct TCB_t* rchild;
int value;
};

void init_TCB (struct TCB_t* tcb, void* function, void* stackP, int stack_size)
 {
   
     memset(tcb, '\0', sizeof(struct TCB_t));
     getcontext(&tcb->context); 
     
     tcb->context.uc_stack.ss_sp =stackP;
     tcb->context.uc_stack.ss_size =(size_t)stack_size;
     makecontext(&tcb->context, function, 0);
     printf("value of context: %d",tcb->context);   
 }
  
