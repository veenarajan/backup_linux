//Sudhashree Gholkar
//Prachi Tanwar
//Archita Chopde


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sem.h"

Semaphore_t *r_sem;
Semaphore_t *w_sem;
Semaphore_t *mutex;
int rwc = 0, wwc = 0, rc = 0, wc = 0, global_ID=0;

void reader_entry(int ID)
{
	P(mutex);
	if (wwc > 0 || wc > 0) 
	{
	    rwc++;		
	    V(mutex);	
	    P(r_sem);	
	    rwc--;		
	}
	rc++;
	if (rwc > 0)
	    V(r_sem);
	else
	    V(mutex);
}

void reader_exit(int ID)
{
	P(mutex);
	rc--;		
	if (rc == 0 && wwc > 0)
	{
	    V(w_sem);
	} else
	    V(mutex);

}

void writer_entry(int ID)
{
	P(mutex);
	if (rc > 0 || wc > 0) 
	{
	    wwc++;		
	    V(mutex);	
	    P(w_sem);	
	    wwc--;		
	}
	wc++;			
	V(mutex);		
}

void writer_exit(int ID)
{
	P(mutex);
	wc--;
	if (rwc > 0) 
	{		
	    V(r_sem);
	} 
	else if (wwc > 0) 
	{	
	    V(w_sem);
	} 
	else 
	{		
	    V(mutex);
	}
}

void reader(void)
{ 
  int ID;
  P(mutex); ID = global_ID++; V(mutex);
  while(1)
  {
	reader_entry(ID);
	sleep(1);
	reader_exit(ID);
  };
}

void writer(void)
{
  int ID;
  P(mutex); ID = global_ID++; V(mutex);
  while(1)
  {
 	writer_entry(ID);
	sleep(1);
	writer_exit(ID);
  };
}

int main()
{ 
    RunQ=(struct TCB_t*)malloc(sizeof(struct TCB_t));
    InitQueue(RunQ); 
    mutex=CreateSem(1);
   r_sem=CreateSem(0);
   w_sem=CreateSem(0);

/*
    start_thread(reader, NULL);

    start_thread(reader, NULL);
    start_thread(writer, NULL);
    start_thread(reader, NULL);
    start_thread(writer, NULL);
    start_thread(writer, NULL);
*/
 start_thread(reader);

    start_thread(reader);
    start_thread(writer);
    start_thread(reader);
    start_thread(writer);
    start_thread(writer);

run();
}   




