%{
	#include <stdio.h>
	int picount = 0, nicount = 0, pfcount = 0, nfcount = 0;
%}

%%
[\t\n]+
[(-0)-(-9)]	{nicount++;}
[0-9]	{picount++;}
%%

main(){
	printf("Enter the text(to end press CTRL + D) : \n");
	yylex();
	printf("\nPositive Integers = %d\nNegative Integers = %d\n",picount,nicount);
}