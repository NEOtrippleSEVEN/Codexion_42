
//To loop threads, we first need to create an array where all the thread handels will be stored.


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t Mutex;


void* thread_routine(){
	for(int i = 0; i < 1000000; i++){
	pthread_mutex_lock(&Mutex);
	mails++;
	pthread_mutex_unlock(&Mutex);
	}
}

int main(int argc, char* argv[]){

	pthread_t th[10];
	pthread_mutex_init(&Mutex, NULL);
	int i;

	// This loop creates as many threads as we need without separatly creating each one.
	for(i = 0; i < 10; i++){
		if(pthread_create(&th[i], NULL, &thread_routine, NULL) != 0){ // First Thread gets created
			perror("Failed to create Thread\n");
			return 1;
		}
		printf("Thread %d has started\n", i);
		// System waits for thread to join. before goin to next.
		// if(pthread_join(th[i], NULL)){
		// 	return 2;
		// }
		// Thread is unlocked and the next in line can continue.
	}
	// This for loop allows us to mutli-thread instead of single thread.
	for(i = 0; i < 10; i++){
		if(pthread_join(th[i], NULL)){
			return 2;
		}
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&Mutex);
	printf("Number of mails: %d\n", mails);
	return 0;
}

// The commented loop doesn't allow you to run multiple threads in parallel, only one by one.
// The creation and joining of threads must be separated in order to allow another thread to execute 
// resulting in multi threading.