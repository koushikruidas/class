#include <stdio.h>
#include <unistd.h>
#include <signal.h>



void main(void) {

	pid_t pid = fork();

	if (pid == 0) {
		printf("Same thing i'm a Zombie\n");
		printf("i am child my pid is :%d\n",getpid());
		
		pid = fork();
		if (pid == 0)
		{
			printf("he heh eh GC\n");
			printf("i am Grand child: %d\n",getpid());

		}
		else
		{
			printf("parent: pid:%d\n",getppid());
			getchar();
		}
	}
	else
	{
		printf("in parent child pid is :%d\n",pid);
		sleep(5);
		kill(pid, SIGKILL);	
		sleep(10);	
	}
}