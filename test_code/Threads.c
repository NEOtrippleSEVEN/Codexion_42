/*
When you create a Thread, you are executing a single task. 
In this case we are learning how to initialise a thread and run it through a simple function.

*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 1. include a link option --> command that compiles source code. 

void* routine(){
	printf("Test from threads\n");

	sleep(3);
	printf("Ending Thread\n");
	// AFter running main, up until here all 3 threads execute at the same time.
	// In order to manage that, see if statements in main.

}

int main(int argc, char* argv[]){
	
	pthread_t t1, t2, t3;

	if(pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1; 
	if(pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 2;
	if(pthread_create(&t3, NULL, &routine, NULL) != 0)
		return 3; // Return values have here no meaning but can be given meaning
	
	if(pthread_join(t1, NULL) != 0)
		return 4;
	if(pthread_join(t2, NULL) != 0)
		return 5;
	if(pthread_join(t3, NULL) != 0)
		return 6;

	return 0;
}

// void* threading_notes(){

// 	// 1. Before initialising, create the thread and `pthread_t` type to store info.
// 	//	This is the STRUCT

// 	pthread_t t1;

// 	// 2. Initialise the Thread with default parameters. Pass reference to the thread `&t1` no attribute so == NULL
// 	// 		then pass the process for the thread `&routine` with NULL as attributes

// 	pthread_create(&t1, NULL, &routine, NULL);


// 	// 3. In order to wait for the thread to finish the process we need to give it some time using
// 	// 		`pthread_join()` function. NULL or a pointer to a value that the process returns as 2nd parameter.

// 	pthread_join(&t1, NULL);

// }

// Now in main we will initialise 2 threads at once. 