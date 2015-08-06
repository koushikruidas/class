%{
	#include <stdio.h>
	int printcount = 0, scanfcount = 0;
%}

%%
printf {printcount++;}
scanf  {scanfcount++;}
%%

main(int argc, char *argv[]){
	yyin = fopen(argv[1],"r");
	yylex();
	printf("\nThe no of printf statement is : %d\n",printcount);
	printf("the no of scanf statement is : %d\n",scanfcount);
}

int yywrap(){
	return 1;
}