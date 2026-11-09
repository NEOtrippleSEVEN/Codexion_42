
// In this program we are going to go into how to get a return value from threads
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void* roll_dice(){
	
	// 3. Since we want results between 0-6 we use modulo 6 and add one
	// 	so the result isn't 5 but 6.
	int value = (rand() % 6 + 1);
	// 7. Here we dynamically allocat memory in the stack then save it into value.
	int* result = malloc(sizeof(int));
	*result = value;

	printf("Func res: %p\n", result);
	printf("Value: %d\n", value);
	// 5. In order to get a value out, we return a reference to a void pointer with a cast. 
	// That is what the function is waiting for.

	return (void*) result; // 6. This would give us seg fault. The fix is dynamically allocating mem to pointer. 
}


int main(int argc, char* argv[]){
	
	// 8. Now int* result is the same as the below value in the main function
	int* res;
	// 2. Seed random gen for rolling the dice.
	srand(time(NULL));

	// 1. we create a thread.
	pthread_t th;

	if(pthread_create(&th, NULL, &roll_dice, NULL) != 0){
		return 1;
	}
	if(pthread_join(th, (void**) &res) != 0){ 
		// 4. So far we generated a random number, now we need to 
		// get the results from the function `roll_dice` into `main`.
		// In this case we use the second parameter in function `pthread_join`.
		// The parameter takes a double pointer to void because of the function being a singel void pointer.
		// so the function takes a reference to a pointer or double pointer, then sets the value to whatever 
		// comes out the function. 
		return 2;
	}
	printf("Main res: %p\n", res);
	printf("Result: %d\n", *res);	// Since variable is a pointer, we need to print the value of it using *
	// 9. We need to free the memory in the main. 
	free(res);
	return 0;
}

// Good exercise would be to make this program run mutliple threads.
// Rolling 8 dice in parallel