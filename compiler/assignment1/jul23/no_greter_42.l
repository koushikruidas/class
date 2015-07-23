%{
	#include <stdio.h>
int postiveno=0;
int negtiveno=0;
int positivefractions=0;
int negativefractions=0;
int count = 0;
%}

DIGIT [0-9]
%%

\+?{DIGIT}+                             {postiveno++; if(atoi(yytext)>42)	count++;}
-{DIGIT}+                             	{negtiveno++;}

\+?{DIGIT}*\.{DIGIT}+            		{positivefractions++; if(atoi(yytext)>42)	count++;}
-{DIGIT}*\.{DIGIT}+               		{negativefractions++;}
%%

main()
{
printf("%s\n", "give input follwed by enter (press CTRL + D to stop)"); 
yylex();
printf("\nNo. of positive numbers: %d",postiveno);
printf("\nNo. of Negative numbers: %d",negtiveno);
printf("\nNo. of Positive fractions: %d",positivefractions);
printf("\nNo. of Negative fractions: %d",negativefractions);
printf("\nNo. of Numbers which are greter than 42 : %d\n",count);
}
int yywrap(){
	return 1;
}