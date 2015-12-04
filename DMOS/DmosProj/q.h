#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include "tcb.h"

int queuegl=0;
void InitQ (struct TCB_t* Q)

{
ucontext_t temp;
Q->lchild=Q;
Q->rchild=Q;
printf("Queue is initialised");   
}


void addQ(struct TCB_t* Q,ucontext_t item)
{
struct TCB_t* parent=(struct TCB_t*)malloc(sizeof(struct TCB_t)); 
struct TCB_t* p=(struct TCB_t*)malloc(sizeof(struct TCB_t));
struct TCB_t* new1=(struct TCB_t*)malloc(sizeof(struct TCB_t));
struct TCB_t* temp=(struct TCB_t*)malloc(sizeof(struct TCB_t));

p=0;

if(Q->lchild!=Q)
{
p=Q->lchild;
parent=Q;
temp=p;


while(p->rchild!=temp)
{
         parent=p;
p=p->rchild;
 

}     
new1->context=item;
    new1->lchild=p;
p->rchild=new1;
new1->rchild=temp;
temp->lchild=new1;
}
else
{
new1->context=item;
new1->rchild=new1;
new1->lchild=new1;
Q->lchild=new1;
  
}
//printf("\n added successfully");
}


void display(struct TCB_t* Q)
{

    struct TCB_t* p=(struct TCB_t*)malloc(sizeof(struct TCB_t));
    struct TCB_t* temp=(struct TCB_t*)malloc(sizeof(struct TCB_t));
   if(Q->lchild==Q)
   {
   printf("Queue is empty");
   }
   else
   {
      p=Q->lchild;
      temp=p;
      while(1)
     {
     //printf(" %d ",p->value);
     p=p->rchild;
      if(p==temp)
      break;
     }
   }



}

struct TCB_t* DelQ(struct TCB_t* Q)
{
     struct TCB_t* p= (struct TCB_t*)malloc(sizeof(struct TCB_t));
struct TCB_t* parent= (struct TCB_t*)malloc(sizeof(struct TCB_t));
struct TCB_t* temp= (struct TCB_t*)malloc(sizeof(struct TCB_t));

        if(Q->lchild==Q)
	{
	   printf("sorry !! queue is empty");
           
	}
        else
        {
         p=Q->lchild;
         parent=Q;
	 temp=p;
         if(p->rchild==p)
         {
		Q->lchild=Q;
         }
          else
           {
                  temp=p->rchild;
                  Q->lchild=temp;
                  temp->lchild=p->lchild;
                  (p->lchild)->rchild=temp;
                   
                
           }
        }
return p;
}



void RotateQ(struct TCB_t* Q)
{

Q->lchild=(Q->lchild)->rchild;
 
}
