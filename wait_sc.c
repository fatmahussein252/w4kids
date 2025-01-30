#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int ch_num;

static void sigInfoHandler(int sig, siginfo_t * si, void *ucontext)
{
	
	printf("Child (PID %d) ", si->si_pid);
	switch (si->si_code) {
	    case CLD_EXITED:
        	printf("exited normally with status: %d\n", si->si_status); ch_num--;
       		break;
	    case CLD_STOPPED:
		printf("was stopped by signal: %d\n", si->si_status); 
		break;
	    case CLD_CONTINUED:
		printf("was resumed by signal: %d\n", si->si_status);
		break;
	    case CLD_KILLED:
		printf("was killed by signal: %d\n", si->si_status); ch_num--;
		break;
	    case CLD_DUMPED:
		printf("terminated abnormally (core dumped) with signal: %d\n", si->si_status); ch_num--;
		break;
	    default:
		printf("received unknown status.\n");
}

		
		
}

void w4kids(int *num_kids)
{
      	struct sigaction sa;
	sa.sa_sigaction = sigInfoHandler;
	sa.sa_flags = SA_NOCLDWAIT | SA_SIGINFO;
	
	sigaction(SIGCHLD, &sa,NULL);
	if(num_kids != NULL){
		*num_kids +=ch_num; 
		ch_num = 0;
		}
	
	return;
}
