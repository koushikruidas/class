#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t n;
	int i;
	n = fork();
	for (i = 0;i<4;i++)
	{
		if(n != 0)
		{
			printf("parent PID is [%d] and %dth child PID is [%d]\n",getpid(),i,n);
			n = fork();
		}
		else
			break;
	}
	return 0;
}