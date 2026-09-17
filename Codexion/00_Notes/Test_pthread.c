#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*take_dongle(void *arg){
	printf("Coder is compiling using Dongles 1 & 2...\n");
	sleep(3);
	printf("Coder has finished compiling.. Dongles are free for use.\n");
	return NULL;
}


int	main(){

	pthread_t Coder_1;
	pthread_t Coder_2;

	pthread_create(&Coder_1, NULL, take_dongle, NULL); //newthread: attr: start_routine: arg:
	pthread_join(Coder_1, NULL); //th: thread_return:
	
	pthread_create(&Coder_2, NULL, take_dongle, NULL); //newthread: attr: start_routine: arg:
	pthread_join(Coder_2, NULL); //th: thread_return:

	return 0;
}
 


