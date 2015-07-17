#include<stdio.h>
#define SIZE 5
void pop(int *,int *);
void push(int *,int *);
void display(int *,int );
int amin()
{
	int stack[SIZE],top=-1,n;
	while(n)
	{
		printf("enter 0 to stop");
		printf("enter 1 to push");
		printf("enter 2 to pop");
		printf("enter 3 to disp");
		scanf("%d",&n);
		switch(n)
		{
			case 1:push(&top,&stack[0]);
			break;
			case 2:pop(&top,&stack[0]);
			break;
			case 3:display(&stack,top);
			break;
		}
	}
}
void push(int *x,int *y)
{
	if(*x==SIZE-1)
	{
		printf("stack is full\n");
		return;
	}
	else
	{
		(*x)++;
		printf("please eneter a value\n");
		scanf("%d",y[*x]);
	}
}
void pop(int *x,int *y)
{
	if(*x<=-1)
	{
		printf("stack is full\n");
		return;
	}
	else
	{
		(*x)--;
		printf("enter a value\n");
		scanf("%d",y[*x]);
	}
}
void display(int *s,int t)
{
	int i;
	if(t==-1)
	{
		printf("error\n");
	}
	else
	{
		for(i=0;i<=t;i++)
		printf("%d",s[i]);
	}
}
