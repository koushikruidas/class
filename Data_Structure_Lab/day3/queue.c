#include<stdio.h>
#define S 4
void inst(int *,int *,int *);
void del(int *,int *,int *);
void disp(int *,int *,int );
int main(void)
{
	int ar[S],front=0,rare=-1,count=0,n=1;
	while(n)
	{
		printf("enter 0 to exit\n");
		printf("enter 1 to insert\n");
		printf("enter 2 to delete\n");
		printf("enter 3 to disp\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: inst(ar,&rare,&count);
			        break;
			case 2: del(ar,&front,&count);
			        break;
			case 3: disp(ar,&front,count);
			        break;
		}
	}
	return 0;
}
void inst(int *a,int *r,int* c)
{
	int v;
	if(*c==S)
	{
		printf("queue is full\n");
		return ;
	}
	printf("plz enter d value\n");
	scanf("%d",&a[*r=(*r+1)%S]);
	//*r=(*r+1)%S;
//	a[*r]=v;
	(*c)++;
}
void del(int *a,int *f,int *c)
{
	if(*c==0)
	{
		printf("queue is empty\n");
		return ;
	}
	printf("deleted data is:%d\n",a[*f]);
	(*f)=(*f+1)%S;
	(*c)--;
}
void disp(int *a,int *f,int c)
{
	int i,j;
	printf("the queue is\n");
	for(i=*f,j=c;j>0;i=(i+1)%S
	,j--)
	{
		printf("		%d\n\n",a[i]);
	}
}
