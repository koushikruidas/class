#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t n;
	int i;
	FILE * f;
	f = fopen("pid.txt", "w");
	printf("MAIN parent id %d\n", getppid());
	n = fork();
	for (i = 0;i<4;i++)
	{
		if(n == 0)
		{
			n = fork();
		}
		else {
			fprintf(f, "parent %d, me %d, child: %d\n",getppid(), getpid(), n);
			sleep(5);
			break;
		}
	}
	return 0;
}