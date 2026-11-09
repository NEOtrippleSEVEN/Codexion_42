/*
Mutex (Mutual Exclustion) is a synchronization primitive used to prevent
multiple threads from accessing shared resources simultaneously. aka preventing Race Conditions.  

Basically a Mutex is used around a block of code to lock and unlock it. 
Making it easier to prevent Race Conditions. 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Standard POSIX Mutex API
#include <pthread.h>

// Functions included: 	
//						pthread_mutex_t;
//						pthread_mutex_init(), 
//						pthread_mutex_lock(), 
//						pthread_mutex_unlock,
//						pthread_mutex_destroy()

int mail = 0;


// First we set the mutex variable.
pthread_mutex_t mutex;


void* thread_routine(){
	for(int i = 0; i < 1000000; i++){
		// After init, we lock right when the function enters.
		
		pthread_mutex_lock(&mutex);
		// Lock
		
		mail ++;
		// Read, Write, Increment
		//printf("%d\n", mail);
		pthread_mutex_unlock(&mutex);
		// unlock.
	}
}

int main(int argc, char* argv[]){

	pthread_t t1, t2;
	// Then after the threads are set, we initialise the Mutex
	// First parameter sets the intended mutex, second the attribute.
	pthread_mutex_init(&mutex, NULL);
	if(pthread_create(&t1, NULL, &thread_routine, NULL) != 0) return 1;
	if(pthread_create(&t2, NULL, &thread_routine, NULL) != 0) return 2;

	if(pthread_join(t1, NULL) != 0) return 3;
	if(pthread_join(t2, NULL) != 0) return 4;
	

	// After the mutex is no longer needed, it must be destroyed.
	pthread_mutex_destroy(&mutex);
	printf("Mail Count After Mutex: %d\n", mail);

	return 0;
}
