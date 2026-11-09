/*

In the following code I will show you the difference between Threads and porcesses.

Porcesses Can have multiple threads inside a thread, hence the difference PID numbers.
You cannot have mutliple processes in a single thread.

Memory:

When forking in a Process we duplicate all variables into the fork, making it easier to modify the values of the variables indiviudally.
With threads, you have all the varaiables for all the threads saved in the same place. Excessable by all. 

*/


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Threads Library
#include <pthread.h>

// Processes Library
#include <sys/wait.h>
#include <sys/types.h>


// This Main function show a single Process
void main_process(){
	int pid = fork();
	if(pid == -1)
		return 1;
	printf("Process id %d\n", getpid());	// Output, two different ID's
	if (pid != 0)
		wait(NULL);
}

// This function shows a single thread

void* routine_thread(){
	printf("Process ID %d\n", getpid()); // Output two of the same ID's 
}
 
// ---------------------------------------------------------------------------------------------------------- // 
// In the following functions we will discover the main differences between the both
// Unified memory of threads vs copied memory of Processes

int main_process_2(int argc, char* argv[]){
	int x = 2;
	int pid = fork();
	
	if(pid == 1)
		return 1;
	if (pid == 0)
		x++;

	sleep(2);
	printf("Value of x after process: %d\n", x);
	if(pid != 0)
		wait(NULL);
	return 0;
}

// Now the same we implement in Threads
int x = 2;

void* routine_thread_2(){
	x++;
	sleep(2);
	printf("Value of x after thread_2: %d\n", x);
}
// output: 3
void* routine_thread_3(){
	sleep(2);
	prinf("Value of x after thread_3: %d", x);
}
// Output: 3

// Main function for Thread

int main_thread(int argc, char* argv[]){
	pthread_t t1, t2;

	if(pthread_create(&t1, NULL, routine_thread, NULL) && pthread_create(&t2, NULL, routine_thread, NULL) != 0){
		return 1;
	}
	if(pthread_join(&t1, NULL) && pthread_join(&t2, NULL)  != 0){
		return 2;
	}
	return 0;
}
