#include<stdio.h>
main()
{
	int arr[10];
	int i,l;
	for(i=0;i<=9;i++)
	{
		printf("enter %d number\n",i+1);
		scanf("%d",&arr[i]);
	}
	printf("the 10 numbers are\n");
	for(i=0;i<=9;i++)
	{
		printf("%d\n",arr[i]);
	}
	l=arr[0];
	for(i=0;i<=9;i++)
	{
		l=arr[i]>l ? arr[i] : l;
	}
	printf("largest num is : %d\n",l);
}
