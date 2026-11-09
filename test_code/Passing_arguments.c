/*

here we are goning ot learn how to pass unique values for each thread.

Now if i have a list of Prime numebrs and I want to get a specific value for each thread in
the list.

*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int		primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	// we then dereference arg into an int
	// in order to be able to use it
	int index = *(int*)arg;

	// Yet we need to cast the pointer to an int pointer
	// in order to derefernce it

	printf("%d\n", primes[index]);
}

int	main(int argc, char *argv[])
{
	pthread_t th[10];

	for (int i = 0; i < 10; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, &i) != 0)
		{
			// If you pass anything in the second NULL,
			// it will be passed into the function
			// and you can actually use it then.
			// if it's a pointer user the referrence of i

			perror(NULL)//("Failure to create Thread\n");
		}

		for (int i = 0; i < 10; i++)
		{
			if (pthread_join(&th[i], NULL) != 0)
			{
			}
			perror(NULL);//("Failure to join Thread\n");
		}
	}
}