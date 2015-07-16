#include<stdio.h>
#define S 20
void push(int *,int *,int *);
void pop(int *,int *,int *);
void disp(int *,int ,int);
main(void)
{
	int a[S],top1=-1,top2=S,n=1;
	while(n)
	{
		printf("enter 0 to stop\n");
		printf("enter 1 to push\n");
		printf("enter 2 to pop\n");
		printf("enter 3 to display\n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1: push(a,&top1,&top2);
				break;
			case 2: pop(a,&top1,&top2);
				break;
			case 3: disp(a,top1,top2);
				break;
		}
	}
}
void push(int *a,int *t1,int *t2)
{
	int i=1;
	while(i)
	{
		printf("enter 1 to push in 1st stack\n");
		printf("enter 2 to push in 2nd stack\n");
		printf("enter 0 to return\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				{
					if(*t1==S/2-1)
					{
						printf("stack is full\n");
						return ;
					}
					(*t1)++;
					printf("enter the value which u want to push\n");
					scanf("%d",&a[*t1]);
				}
				break;		
	case 2:
				{
					if(*t2==S/2)
					{
						printf("stack is full\n");
						return ;
					}
					(*t2)--;
					printf("enter the value which u want to push\n");
					scanf("%d",&a[*t2]);
				}
		}
	}
}
void pop(int *a,int *t1,int *t2)
{
	int i=1;
	while(i)
	{
		printf("enter 1 to use 1st stack\n");
		printf("enter 2 to use 2nd stack\n");
		printf("enter 0 to return\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				{
					if(*t1==-1)
					{
						printf("stack is empty\n");
						return ;
					}
					(*t1)--;
					printf("deleted data is:-%d\n",a[*t1+1]);
				}
				break;
			case 2:
				{
					if(*t2==S)
					{
						printf("stack is empty\n");
						return ;
					}
					(*t2)++;
					printf("deleted data is:-%d\n",a[*t2-1]);
				}
		}
	}
}
void disp(int *a,int t1,int t2)
{
	int i=1;
	while(i)
	{
		printf("enter 1 to see 1st stack\n");
		printf("enter 2 to see 2nd stack\n");
		printf("enter 0 to return\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				{
					int j;
					printf("1st stack is ::--\n");
					if(t1==-1)
					{
						printf("stack 1 is empty\n");
						return ;
					}
					for(j=t1;j>=0;j--)
						{
							printf("		%d\n\n",a[j]);
						}
				}
				break;
			case 2:
				{
					int j;
					printf("2nd stack is::--\n");
						if(t2==S)
						{
							printf("stack is empty\n");
							return ;
						}
						for(j=t2;j<S;j++)
						{
							printf("		%d\n\n",a[j]);
						}
				}
		}
	}
}
