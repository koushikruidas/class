#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void main(void) {

	int i=0, j=0;

	if (fork() == 0)
	{
		printf ("I am the zombie \n");
	}
	else
	{
		for(i=0; i <=1000000  ;i++)
		{
			for(j=0;j<=1000;j++)
			{}
		}
		signal(SIGCHLD,SIG_IGN);
	}
}