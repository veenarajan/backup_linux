#include <stdio.h>
#include <ucontext.h>
#include <string.h>
#include <stdlib.h>


//Task control block structure
typedef struct TCB_t
{
	ucontext_t context;
	struct TCB_t *next;
	struct TCB_t *prev;

}TCB_t;

TCB_t *RunQ = NULL;	//global header pointer

void init_TCB(TCB_t *tcb, void *function, void *stackP, int stack_size)
{
	memset(tcb, '\0', sizeof(TCB_t));
	
	//The function initializes the structure pointed at by tcb->context to the currently active context.
	getcontext(&tcb->context);
	
	//uc_stack is the stack used by this context sp-stack pointer
	tcb->context.uc_stack.ss_sp = stackP;
	
	tcb->context.uc_stack.ss_size = (size_t)stack_size;
	makecontext(&tcb->context, function, 0);
	
	//program execution continues by a call to the function func specified as the second argument of that call to makecontext
}
