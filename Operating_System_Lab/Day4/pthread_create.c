#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *kou(void *ari);

int main (void)
{
	
	pthread_t tid;

	
	pthread_create(&tid,NULL,kou,"thread created be happy :) :)");
	pthread_join(tid,NULL);

	exit(0);
}


void *kou(void *ari) {
	char *str;
	str = (char*) ari;
	printf("%s\n",str);
	return NULL;
}
