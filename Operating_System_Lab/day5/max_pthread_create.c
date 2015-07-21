#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *kou(void *ari);

int main (void)
{
	int k = 0,i = 0;
	pthread_t tid;

	while (1) {
	k = pthread_create(&tid,NULL,kou,NULL);
		i++;
		if(k != 0)
			break;

	}
	printf("the total number of thread : %d\n",i);
	exit(0);
}


void *kou(void *ari) {
/*	pthread_t j;

	j = pthread_self();
	//char *str;
	//str = (char*) ari;
	//printf("%s\n",str);
	return NULL;
	*/
}
