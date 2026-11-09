/*
This program's mission is to use mutli-threading operation to roll a dice of six.

*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t mutex;

void* roll_dice(){
	pthread_mutex_lock(&mutex);
	int value = (rand() % 6 + 1);

	int *results = malloc(sizeof(int));
	if(results == 0)
		exit(EXIT_FAILURE);
	*results = value;
	printf("Value: %d\n", value);
	pthread_mutex_unlock(&mutex);

	return (void**) results;
}

int	main(/*int argc, char* argv[]*/){

	pthread_t t1[4];
	int *res;
	srand(time(NULL));
	
	pthread_mutex_init(&mutex, NULL);
	for(int i = 0; i < 4; i++){
		//printf("Thread: %ld\n", t1[i]);
		if(pthread_create(&t1[i], NULL, &roll_dice, NULL) != 0)
			return 1;
		}
	for(int i = 0; i <4; i++){
		if(pthread_join(t1[i], (void**) &res) != 0)
			return 2;
		free(res);
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}


// BUGS:


// roll_dice returns nothing. what writes into res in this case? adn what free(res) then does with it?

// Freeing outsode the loop results in memory leaks. Freeing only once is bad. Need to be inside the loop.

//