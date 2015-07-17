#include<stdio.h>
#include<string.h>
#define SIZE 10

void push(int *,int *);
int pop(int *,int *,int *);
void push2(int *,int *,int );
void disp(int *,int *,int *,int *,int *);

int main(void)
{
	int stack1[SIZE],stack2[SIZE], top1=-1,top2=-1,n=1,v,front=0;
	while(n)
	{
		printf("enter 0 to stop\n");
		printf("enter 1 to push\n");
		printf("enter 2 to pop\n");
		printf("enter 3 to display the queue\n");

		scanf("%d",&n);

		switch(n)
		{
			case 1: push(stack1,&top1);
				break;
			case 2: v = pop(stack1,&top1,&front);
//				push2(stack2,&top2,v);
				break;
			case 3: disp(stack2,&top2,stack1,&top1,&front);
				break;
		}
	}
	return 0;
}
void push(int *st1,int *t1)
{
	printf("enter the value plz::-\n");
	(*t1)++;
	scanf("%d",&st1[(*t1)]);
	if((*t1) == SIZE - 1)
	printf("stack is full\n");
}

/*void push2(int *st2,int *t2,int v)
{
	(*t2)++;
	st2[(*t2)] = v ;
}*/

int pop(int *st1,int *t1,int *f)
{
	int i,j;
	if((*t1) == -1)
	printf("stack is empty\n");	
	return (st1[(*f)++]);
	(*f)++;
}

void disp(int *st2,int *t2,int *st1,int *t1,int *f)
{
	int i,j;
	for(j=(*f);j<=(*t1);j++)
	{
		printf("----------%d--------\n",st1[j]);
	}
/*	for(i=0;i<(*t2);i++)
	{
		printf("--------%d----------\n",st2[i]);
	}*/
}		
