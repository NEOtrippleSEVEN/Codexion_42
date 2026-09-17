# Threads

## What is a thread?

A thread is one independant sequence of instructions running inside a program. The OS can schedule it separatly from other threads. 

In codexion, a thread is one coder doing one job in it's cycle: Get Dongle, Compile, Debug, Refactor...


Example Code: 

```c
#include <stdio.h>
#include <unistd.h>

void	get_dongle(char *C1){

	printf("%s is using Dongle 1 & 2...\n", C1);
	sleep(3);
	printf("%s, has done using dongle...\n", C1);
}

int main()
{
	char *C1;
	C1 = "Coder 1";
	get_dongle(C1);
	
}
```


So now we know how to create one thread. Now we need to find a way to not only create but manipulate and terminate threads. 

> using the `#include <pthread.h>`. This header tells your C compiler to include the POSIX threads defs before compiling the file. 

The header gives acces to pthread types and functions used for multi-threading. 



```c 
#include <pthread.h>

pthread_t			coder_thread;
pthread_mutex_t		log_mutex;
```
> 1st line makes pthread tools known to the compiler, it doesn't create a thread or mutex. 

> Initialisation and use must still be made, in the Makefile as in    `-pthread` so the lib is linked correctly. 



Main features:

1. Thread Creation & termination.
2. Mutexes (for data protection)
3. Condition variables (for event waiting)
4. Thread specific data
5. Thread Attributes.
6. Synchronization primitives like barriers. 

Header Includes:

- `pthread_create()` 	-> starts a (coder) thread.
- `pthread_exit()`		-> Terminate Thread. 
- `pthread_join()` 		-> waits for a thread to finish. 
- `pthread_mutex_t` 	-> represents a mutex that protects shared data. 
- `pthread_mutex_lock()` & `.._unlock()` ->  locks & unlocks mutex.
- `pthread_t` 			-> A variable type that represents a thread. 
- `pthread_cond_t`		-> Represents a condition variable for safely waiting and waking threads. 


Usage: Compiling often relies on linkage of `-lpthread`.

Issues: `pthread` if used incorrectly can result in Deadlock, race conditions, and other concurrency-related bugs. 


#### Threads always run concurrently not parallel completely.

1. Hardware Limiation -> CPU can only run one thread at a time becuase it has one core. 

2. Locks & Synchronization -> Locks are used to force threads to wait their turn. Two threads accessing the same memory locaiton can interfere with each other, due ot cahce coherency protocol. 

3. Memory Access -> Threads might be waiting to be loaded from main memory causing delays. 

4. OS Scheduling -> The OS decides how to allocate CPU time to various threads depending on it's decisions, not all threads may run. 