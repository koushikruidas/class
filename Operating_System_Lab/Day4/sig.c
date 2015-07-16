#include <stdio.h>
#include <signal.h>

void func();
void main(void) {
	pid_t pid;
	pid = fork();

	if(pid == 0)
	{
		printf("I am a zombie he he \n");
		printf("You can't terminate me using 'ctrl+c'\n");
	}
	else
	{
		
		signal(SIGINT,func);
		getchar();
	}
}

void func() {
	printf("  hhe he what happen dear i told You\n");
}