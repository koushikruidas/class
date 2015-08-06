%{
#include <stdio.h>
int cm = 0;
%}

%%

.*"and".* {cm = 1;}
.*"or".* {cm = 1;}
.*"but".* {cm = 1;}
%%

main(){
	yylex();
	if(cm == 1){
	printf("compound \n");
	}
	else
	printf("not compound\n");
}
int yywrap(){
	return 1;
}