#include <stdio.h>

int main(){
	int nter, nnonter,stsym,ii,npro,jj;
	char terminal[10],nonterminal[10];
	char rule[10][10];

	printf("enter the number of terminals : " );
	scanf("%d",&nter);
	printf("enter the terminal symbols : ");
	// int dummy
	for(ii = 0; ii < nter; ii++){
		printf("enter %dth terminal : ",ii+1);
		scanf("%*c%c",&terminal[ii]);
	}

	// for(ii = 0; ii < nter; ii++){
	// 	printf("the terminals are : [%c]\n",terminal[ii] );
	// }

	printf("enter the number of non terminals : ");
	scanf("%d",&nnonter);
	printf("enter the non-terminal symbols : ");
	for(ii = 0 ; ii < nnonter; ii++){
		printf("enter %dth non-terminal : ",ii+1);
		scanf("%*c%c",&nonterminal[ii]);
	}

	// for(ii = 0; ii < nnonter; ii++){
	// 	printf("the non terminals are : [%c]\n",nonterminal[ii] );
	// }

	for(ii = 0; ii < nter; ii++){
		printf("enter the number of transition for terminal %c : ",terminal[ii] );
		scanf("%d",&npro);
		for(jj = 0 ; jj < npro; jj++){
			printf("%c -> ",terminal[ii]);
			scanf("%*c%c",&rule[ii][jj]);
		}
	}

	for(ii = 0; ii < nter; ii++){
		for(jj = 0 ; jj < npro; jj++){
			printf("%c -> %c \n",terminal[ii],rule[ii][jj] );
		}
	}

	return 0;
}