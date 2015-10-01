#include <stdio.h>
#include <string.h>

int ninputs = 0;
int dfa[10][10];
int c1[10]; 
char string[10];
int check(char , int);

int main()
{
	

	int nstates, nfinals;
	int yeno = 0;
	int f[10];
	int i,j, s = 0, final = 0;
	printf("%s\n", "enter the number of states : ");
	scanf("%d",&nstates);
	printf("%s\n", "enter the no. of input symbol : ");
	scanf("%d",&ninputs);
	printf("the value of ninputs : %d\n",ninputs );

	printf("%s\n", "enter inputs : ");
	for(i=0; i < ninputs; i++){
		printf(" %d ",i);
		scanf("%d",&c1[i]);
	}


	printf("%s\n", "Enter the num of finals state : ");
	scanf("%d",&nfinals);

	for(i = 0; i < nfinals; i++){
		printf("\n\nFinal state %d :  q",i+1);
		scanf("%d",&f[i]);
	}

	printf("--------------------------------------------------------------");
	printf("%s\n", "transition rule (initital state, final state = final state) ");

	for(i = 0; i < ninputs; i++){
		for(j =0; j < nstates; j++){
			printf("\n(q%d , %d = q",j,c1[i]);
				scanf("%d",&dfa[i][j]);
			printf(")");
			}
		}

		do
		{
			i=0;
			printf("\n\nEnter Input String.. ");
			scanf("%s",string);

			while(string[i]!='\0')
				if((s=check(string[i++],s))<0)
					break;
				for(i=0 ;i<nfinals ;i++)
					if(f[i] ==s )
						final=1;
					if(final==1)
						printf("\n valid string"); 
					else
						printf("invalid string");
					printf("\nDo you want to continue.?  \n(y = 1 or n = 0) ");
					scanf("%d",&yeno);
				}
				while(yeno == 1);
			}

int check(char b, int d){
	int j;

	for(j = 0; j < ninputs; j++)
		if(b == c1[j]);
	return (dfa[d][j]);
	return -1;
}