%{
	#include <stdio.h>
	int count = 0;
%}

%%
((4[2-9])|([5-9][0-9])|([1-9][0-9][0-9])+)\.[0-9]*[1-9][0-9]*	{count ++;}
-((4[2-9])|([5-9][0-9])|([1-9][0-9][0-9])+)\.[0-9]*[1-9][0-9]*	;
^(4[3-9])|([5-9][0-9])|([1-9][0-9][0-9]+)$		{count ++;}
[ \t\n]+			;
%%

int main(void){
	yylex();
	printf("No of greater than 42 is : %d\n",count);
	return 0;
}

int yywrap(void){
	return 1;
}