#include<stdio.h>
#include<string.h>

#define S 100

void push(char *,int *,char );
int pop(char *,int *);
void disp(int ,char *,int *,char *);

int main(void)
{
	char op1[S],ar[S],infix[S];
	int top1=-1,count=0,len,i=0,j,v,k;

	printf("enter the infix expression\n");
	scanf("%s",&infix);
	len=strlen(infix)-1;
	for(k=0;k<=len;k++)
	{
		if(isdigit(infix[k]))
		{
			ar[i] = infix[k];
			i++;
		}
		else
		{
			switch(infix[k])
			{
				case '(': push(op1,&top1,infix[k]);
				        break;
				case ')':
						{
							for(j=top1;op1[j]!='(';j--)
							{

							v = pop(op1,&top1);
							 ar[i] = v;
							 i++;
							}
						}
						break;
				case '-':
						{
							if(op1[top1]=='+' || op1[top1]=='*' || op1[top1]=='/')
							{
								for(j=top1;op1[j]!='(';j--)
								{
									v = pop(op1,&top1);
									ar[i] = v;
         							i++;
								}
							}
							else
							{
								push(op1,&top1,infix[k]);
							}
						}
						break;
				case '+':
						{
							if(op1[top1]=='*' || op1[top1]=='/')
							{
								for(j==top1;op1[j]!='(';j--)
								{
									v = pop(op1,&top1);
         							ar[i] = v;
									 i++;
								}
							}
							else
							{
                                push(op1,&top1,infix[k]);
							}
						}
						break;
				case '*':
						{
							if(op1[top1]=='/')
							{
                                	for(j==top1;op1[j]!='(';j--)
								{
									v = pop(op1,&top1);
         							ar[i] = v;
									 i++;
								}
							}
							else
							{
                                push(op1,&top1,infix[k]);
							}
						}
						break;
				case '/': push(op1,&top1,infix[k]);
				            break;
			}
		}
	}
	disp(i,ar,&top1,&op1);
	return 0;
}
void push(char*op,int*t1,char in)
{

	op[++(*t1)] = in;
}
int pop(char *op1,int *t1)
{
    return(op1[(*t1)--]);
}
void disp(int i,char*ar,int *t1,char *op1)
{
	int m;

	for(m=0;m<i;m++)
	{
		printf("%c",ar[m]);
	}
	for(m=(*t1);m>-1;m--)
	{
		if(op1[m]!='(')
		printf("%c",op1[m]);
	}
}
