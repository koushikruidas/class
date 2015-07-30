%{
	#include <stdio.h>
	int space = 0,character = 0,words = 0,newline = 0, e =0;
%}

%%
[ ]+		{space++;}
[.]+		{character++;}
[a-zA-Z]+|[A-Za-z0-9]*	{
words++;
character+= yyleng;}
[\n]+		{newline++;}
[\t]+		{space+=4;}
%%

int main(int argc, char *argv[]){
	yyin = fopen(argv[1],"r");
	yylex();
	fclose(yyin);
	printf("no of space : %d\n",space);
	printf("no of character : %d\n",character);
	printf("no of words : %d\n",words);
	printf("no of newline : %d\n",newline);

}