%{
	#include <stdio.h>
	int count = 0;	
%}

%%
^abb.*ccd$	{count++;}
%%
main(){
	printf("Enter the text(to end press CTRL + D) : \n");
	yylex();
	printf("The no. of string which starts with abb and end with ccd is : %d\n",count);
}

int yywrap(){
	return 1;
}