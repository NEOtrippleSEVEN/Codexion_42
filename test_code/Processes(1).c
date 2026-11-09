#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>

// Ledger 

uint64_t ledger;


int main(){

	pid_t pid = fork();

	// Child Process
	if( 0 == pid)
	{
		ledger += 42;
		printf("CHILD ledger --> %llu\n", ledger);
	}

	// Father Process
	else
	{
		ledger += 42;
		printf("FATHER ledger --> %llu\n", ledger);
	}
}