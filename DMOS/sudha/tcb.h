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
 // char st2[512];
 
   
     memset(tcb, '\0', sizeof(struct TCB_t));       // wash, rinse
     getcontext(&tcb->context);  // have to get parent context, else snow forms on hell
     
     tcb->context.uc_stack.ss_sp =stackP;
     tcb->context.uc_stack.ss_size =(size_t)stack_size;
     //tcb->context.uc_link=&RunQ;
     makecontext(&tcb->context, function, 0);// context is now cooked
     //printf("value of context: %d",tcb->context);   
 }
  
