#include<stdio.h>
#include<string.h>
main()
{
	int i,l;
	char str[50];
	printf("enter the string\n");
	gets(str);
	l=strlen(str)-1;
	printf("the reverse string is :\n");
	for(i=l;i>=0;i--)
	{
		printf("%c",str[i]);
	}
	printf("\n");
	return 0;
}
