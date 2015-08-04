%{
	#include <stdio.h>
	int count = 0;	
%}

%%
[a-zA-z]+[_]*([a-zA-Z]|[0-9])*$	{count++;}
%%
main(){
	printf("Enter the text(to end press CTRL + D) : \n");
	yylex();
	printf("The no. of ident9ifire is : %d\n",count);
}

int yywrap(){
	return 1;
}