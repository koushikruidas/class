#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *kou(void *ari);

int i  = 0;

int main (void)
{
	int k = 0;
	pthread_t tid;

	while (1) {
	k = pthread_create(&tid,NULL,kou,NULL);
		if(k != 0)
			break;

	}
	printf("the total number of thread : %d\n",i);
	exit(0);
}


void *kou(void *ari) {

	i++;
	return NULL;
	
}
