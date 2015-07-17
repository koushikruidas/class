#include<stdio.h>
main()
{
	int a,b,i,c=0;
	printf("enter a no.\n");
	scanf("%d",&a);
	i=a;
	while(i!=0)
	{
		b=i%10;
		i=i/10;
		c=10*c+b;
//		printf("%d",c);
	}
	if(c==a)
	printf("its a palindrom number\n");
	else
	{printf("c=%d\n",c);
	printf("its not a palindrome number try again\n");
	}
}
