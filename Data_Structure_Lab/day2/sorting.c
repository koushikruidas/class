
#include<stdio.h>
#define SIZE 8
void Push(int *,int *,int *,int *,int *,int *,int );
void Pop(int *,int *,int *,int *,int *,int *);
void Disp(int *,int *,int *,int *,int *,int *);
int main()
{
	int a[SIZE],b[SIZE],c[SIZE],t1=-1,t2=-1,t3=-1,r=0;
	int n=1;
	while(n)
	{
		printf("\nEnter 0 to stop");
		printf("\nEnter 1 to push");
		printf("\nEnter 2 to pop");
		printf("\nEnter 3 to display the sorted array\n");
		printf("Enter your choice::");
		scanf("%d",&n);
		switch(n)
		{
			case(1):
			        {
			        Push(&t1,&t2,&t3,a,b,c,r);
				r++;
			        }
				break;
			case(2):{
				Pop(&t1,&t2,&t3,a,b,c);
				r--;
				}	
				break;
			case(3):Disp(&t1,&t2,&t3,a,b,c);
				break;
		}
	}

}

void Push(int *t1,int *t2,int *t3,int *a,int *b,int *c,int r)
{
	if(r==SIZE)
	 {
	 printf("\nyou cannot enter anymore values\n");
	 return;
	 }
	 else
	 {
	int n=0;
	printf("\nYou can enter at most %d numbers for sorting",SIZE);
	printf("\nEnter 1 to enter to the first stack:-\n,2 to enter to the second stack:-\n 3 to enter to the third stack:-\n");
	scanf("%d",&n);
	 
		switch(n)
		{
			case (1):
			{
				if((*t1)==(SIZE-1))
				{
					printf("The Stack is full.\n");
					return;
				}
				else
				{
					(*t1)++;
					printf("\nEnter your value:");
					scanf("%d",&a[(*t1)]);
					
				}
			break;
			}
			case 2:
			{

				if((*t2)==(SIZE-1))
				{
					printf("The Stack is full.\n");
					return;
				}
				else
				{
					(*t2)++;
					printf("\nEnter your value:");
					scanf("%d",&b[(*t2)]);
					
				}
			break;
			}
                        case 3:
			{

				if((*t3)==(SIZE-1))
				{
					printf("The Stack is full.\n");
					return;
				}
				else
				{
					(*t3)++;
					printf("\nEnter your value:");
					scanf("%d",&c[(*t3)]);
					
				}
			break;
			}
		}
	}
}

void Pop(int *t1,int *t2,int *t3,int *a,int *b,int *c)
{
	int n;
	printf("\nFrom which stack do you wish to delete values?");
	scanf("%d",&n);
	if(n!=1 || n!=2 || n!=3)
	{
		printf("There exists no such stack as stack %d",n);
	}
	else
	{
		switch(n)
		{
			case(1):
			{
				if(*t1==-1)
					printf("The stack is empty!");
				else
				{
					printf("The deleted value is %d",a[*t1]);
					(*t1)--;
				}
			break;
			}
                        case(2):
			{
				if(*t2==-1)
					printf("The stack is empty!");
				else
				{
					printf("The deleted value is %d",a[*t2]);
					(*t2)--;
				}
			break;
			}
                        case(3):
			{
				if(*t3==-1)
					printf("The stack is empty!");
				else
				{
					printf("The deleted value is %d",a[*t3]);
					(*t3)--;
				}
			break;
			}
		}
	}
}


void Disp(int *t1,int *t2,int *t3,int *a,int *b,int *c)
{	
	int d=(*t1);
	int e=(*t2);
	int f=(*t3);
	int i,j;
	for(i=d;i>=0;i--)
	{
		e++;
		b[e]=a[d];
		d--;
	}
	for(j=f;j>=0;j--)
	{
		e++;
		b[e]=c[f];
		f--;
	}
	
	while(e!=-1)
	{

		
		int max=b[e];
		int k;
		for(k=(e-1);k>=0;k--)
		{
			max=b[k]>max?b[k]:max;
		}
		int l;
		for(l=e;l>=0;l--)
		{
			if(b[e]==max)
			{
				f++;
				c[f]=b[e];
				e--;
			
			}
			else if(b[e]!=max)
			{
				d++;
				a[d]=b[e];
				e--;
			}	
		}
		int m;
		for(m=d;m>=0;m--)
		{	
			e++;
			b[e]=a[m];
			d--;
		}
		
	}
	
	int x;
	for(x=f;x>=0;x--)
	{
		printf("\n\t%d\n",c[x]);
	}
}
		
		
		
	
		
