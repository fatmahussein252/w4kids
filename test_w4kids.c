#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>


extern void w4kids(int *num_kids);
 
int num_kids;
int main() {
    pid_t p1, p2, p3;
    
    p1 = fork();
    num_kids++;
    if (p1 == 0) {
        // First child - normal exit
	printf("Child 1 (PID %d) running and exiting...\n", getpid());
        exit(42);
    }
    else if (p1>0) {
	p2 = fork();
	num_kids++;
	if(p2 == 0){
	// Second child - stop itself
        printf("Child 2 (PID %d) running and will be stopped...\n", getpid());
        raise(SIGSTOP);  // Send SIGSTOP to itself
        exit(0);
	}
	else if (p2 > 0)
	{
	p3 = fork();
	num_kids++;
	if (p3 == 0){
	// third child waiting to be killed
	printf("Child 3 (PID %d) running and will be killed...\n", getpid());
        while (1) pause();  // Infinite loop, waiting to be killed
	}
	else if (p3>0)
	{
	int c_pid; 
	 while(num_kids>0){
	 w4kids(&num_kids);
	 printf("number of kids = %i\n",num_kids);
	 sleep(1);
	 }

	 return 0;

	
	}
	}
    }

}

