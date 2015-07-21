#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void main(void) {
	
	int i = 0,j = 0;

	if(fork() == 0)
	{
		printf("I am in Zombie state for few seconds\n");
	}
	else
	{
		for(i=0; i <=1000000  ;i++)
		{
			for(j=0;j<=1000;j++)
			{}
		}
		printf("Back from Zombie State\n");
		wait();
	}
}