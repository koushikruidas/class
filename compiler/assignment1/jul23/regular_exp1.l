%{
	#include <stdio.h>
	int count = 0, abcount = 0;	
%}

%%
("abb")[a-zA-Z]*("ccd")	{
count++;
abcount++;}
[a-zA-Z]*("ab")[a-zA-Z]*	{count++;}
%%
main(){
	printf("Enter the text(to end press CTRL + D) : \n");
	yylex();
	printf("The no. of string which starts with abb and end with ccd is : %d\n",count);
	printf("The no. of string containing ab is : %d\n",abcount);
}

int yywrap(){
	return 1;
}