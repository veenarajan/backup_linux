/*
@ Name: Uma Satish Kulkarni (1207684864)
@ Veena Sunder Rajan (1207769429)
CSE 531 DMOS 
Project 1
Title: To wite routines that allow a program to run with multi threads, using non-preemptive scheduling.
*/

#include "threads.h"

int global;
void function_1();
void function_2();

int main()
{
	initQ(RunQ);

	start_thread(function_1);
	start_thread(function_2);

	run();
	
	return 0;
}

void function_1()
{
	int local;
	while(1)
	{
		printf("Printing from function 1 Global= %d Local = %d\n",global, local);
		sleep(1);
		global++;
		local++;
		printf("Function 1 yielding ... Global = %d Local= %d\n",global, local );
		sleep(1);
		yield();
		printf("Function 1 reminder\n");
		sleep(1);
		yield();

	}

}
void function_2()
{
	int local;
	while(1)
	{
		printf("Printing from function 2 Global= %d Local = %d\n",global, local);
		sleep(1);
		global++;
		local++;
		printf("Function 2 yielding ... Global = %d Local= %d\n",global, local );
		sleep(1);
		yield();
		printf("Function 2 reminder\n");
		sleep(1);
		yield();

	}

}
