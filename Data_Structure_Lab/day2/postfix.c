#include<stdio.h>
#include<string.h>
#define SIZE 40

void push(int *s,int *t,int v);
int pop(int *s,int *t);

int main(void)
{
	int top = -1, i, stack[SIZE], len, res, v1, v2;
	char postfix[SIZE];
	
	printf("enter the postfix expression\n");
	fgets(postfix, SIZE, stdin);

	len=strlen(postfix);
	
	for(i=0;i<len;i++)
	{
		if(isdigit(postfix[i]))
		{
			push(stack, &top, (postfix[i] - 48));
		}
		else
		{
			switch(postfix[i])
			{
				case '+':	v1 = pop(stack, &top);
				   			v2 = pop(stack, &top);
							res = v2+v1;
						  	break;
				case '-':	v1 = pop(stack, &top);
   							v2 = pop(stack, &top);
							res = v2-v1;
						  	break;
				case '*':	v1 = pop(stack, &top);
   							v2 = pop(stack, &top);
			   				res = v2*v1;
						  	break;
				case '/':	v1 = pop(stack, &top);
   							v2 = pop(stack, &top);
							res = v2/v1;
						 	break;
			//	default:    printf("wrong input!\n");
				   //         break;
			}
			push(stack, &top, res);
		}
	}
	printf("the solun. is :%d\n",pop(stack,&top));
	return 0;
}
void push(int *s,int *t,int v)
{
 	(*t)++;
	 s[*t]=v;
}
int pop(int *s,int *t)
{
	return s[(*t)--];
}
