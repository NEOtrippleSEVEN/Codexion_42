/*

Race Condition is the process of avoiding value corruption from threads writing to
an already ran thread's output. 

Race Condityions happen when the waiting thread reads the already incremented value 
from the first thread. So the t2 looks at the CPU register instead of memory skipping 
and corrupting data. 

*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


// Let's say we are incrementing everytime an email comes in.

int mail = 0;

void* thread_routine(){
	for(int i = 0; i < 1000000; i++)
		mail++;
	printf("The number of mails: %d\n", mail);
	sleep(3);

	// The process: 
	
	// read mail
	// increment 
	// write mails 
}

int main(int agrc, char* argv[]){
	pthread_t t1, t2;

	if(pthread_create(&t1, NULL, &thread_routine, NULL) != 0)
		return 1;
	if(pthread_create(&t2, NULL, &thread_routine, NULL) != 0)
		return 2;
	if(pthread_join(t1, NULL) != 0)
		return 3;
	if(pthread_join(t2, NULL) != 0)
		return 4;
}

/*
 incrementing i using two threads can lead to faulty values. 

 increment to 100: output: 200 (2 threads --> Correct)

 increment to 1,000 output: 2,000 (2 threads still --> Correct)

 Increment to 100 000 ouput: 200,000 (2 threads still --> Correct)

 Increment to 1 000 000 output shows change: 1123667 instead of 2000000. Why?


 This is what's happening insdie the thread function:
 

 thread reads(i), increments +1, then writes (2).
 at the end, the written and saved number would be (7)
 
 meaning Thread 2 starts it's process during the writing phase of Threas 1, 
 then it uses the wrong value of (7) and either increments only once or none. 
 Resulting in a wrong end value. 



 incrementing + 1

 Thread 1:		1	2	3	4	5	6	7	--> written number is (7)	  

 Thread 2:		1	7	2


 Thread 2 checks the wrong value to increment on, if the end value is taken incrementing can only happen 
 on the first value not on the (7).

*/