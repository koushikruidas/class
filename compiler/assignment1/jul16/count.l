%{
	#include <stdio.h>
	int vcount = 0, ccount = 0;
%}

%%
[\t\n]+
[aeiouAEIOU]	{vcount++;}
[a-zA-Z]	{ccount++;}
%%

main(){
	printf("Enter the text(to end press CTRL + D) : \n");
	yylex();
	printf("\nVowel = %d\nConsonants = %d\n",vcount,ccount);
}