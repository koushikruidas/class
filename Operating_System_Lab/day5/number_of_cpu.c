#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void *thread1(void *arg1);
void *thread2(void *arg2);

void main (void) {
	int k,i,j;
	pthread_t tid1,tid2;
	
	i = sysconf(_SC_NPROCESSORS_ONLN);							/* ###### for getting the number of cpus #### */
	printf("The number of cpus in my Desktop is : %d\n\n",i);


	pthread_create(&tid1,NULL,thread1,"This is First Thread");
	pthread_create(&tid2,NULL,thread2,"this is the second thread");

	getchar();		


	k = pthread_join(tid1,NULL);
	j = pthread_join(tid2,NULL);
	
	printf("thread1 is terminated with pthread_join value : %u\n",(unsigned)k);
	printf("thread2 is terminated with pthread_join value : %u\n",(unsigned)j);


}

void *thread1(void *arg1) {

	double time_spend;
	int i;
	clock_t begin , end;

	begin = clock();

	FILE *fp1;
	fp1=fopen("data1.dat","w");

	int m = pthread_self();
	char *str;
	str = (char*) arg1;
	printf("%s with thrad id : %u\n\n",str,(unsigned)m);

	for(i = 0; i <= 1000000000; i++){}

	end = clock();

	time_spend = (double)(end - begin )/CLOCKS_PER_SEC;

	printf("%lf\n",time_spend);

	fprintf(fp1,"%lf",time_spend);
	fclose(fp1);

	return NULL;
}

void *thread2(void *arg2) {

	double time_spend;
	int i;
	clock_t begin , end;

	begin = clock();

	FILE *fp2;
	fp2=fopen("data2.dat","w");

	int m = pthread_self();
	char * str;
	str = (char*) arg2;
	printf("%s with thread id : %u\n\n",str,(unsigned)m);
	for(i = 0; i <= 1000000000; i++){}
	
	end = clock();

	time_spend = (double)(end - begin )/CLOCKS_PER_SEC;

	printf("%lf\n",time_spend);

	fprintf(fp2,"%lf",time_spend);
	fclose(fp2);

	return NULL;

}