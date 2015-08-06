%{
#include<stdio.h>
int n = 0;
%}
%%
"//".*	{n++;}
"/*".*"*/" {n++;}
%%
main()
{
yylex();
printf("no o fcomment line is : %d\n",n);
return 0;
}
int yywrap()
{
	return 1;
}