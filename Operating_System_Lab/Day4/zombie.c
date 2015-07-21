#include <stdio.h>
#include <unistd.h>

void main(void) {
	pid_t pid = fork();
	
	if(pid == 0)
	{
		printf("I am in the child\n");
		printf("my pid is : %d\n",getpid());
	}
	else
	{ 
		printf("parent my pid is %d\n",getpid());
		getchar();
		
	}
}
