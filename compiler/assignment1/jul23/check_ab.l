%{
	#include <stdio.h>
	int count = 0;	
%}

%%
(ab)+	{count++;}
%%
main(){
	printf("Enter the text(to end press CTRL + D) : \n");
	yylex();
	printf("The no. of string which starts with ab is : %d\n",count);
}

int yywrap(){
	return 1;
}