#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char *encryption(char *, int );
void decryption(char *, int );
int main(){
	int n;
	char *cyphertext;
	char *str; 
	printf("%s\n", "enter a string");
	scanf("%s",str);
	printf("%s\n", "enter the key : ");
	scanf("%d", &n);

	cyphertext = encryption(str,n);

	printf("%s\n", cyphertext);
	printf("\n");
	decryption(cyphertext,n);
	
	return 0;

}

char *encryption(char *s,int k){
	char **Matrix, *Encrypted_matrix ;
	int ROW, COLUMN, i, len, j, c = 0;
	ROW = k;
	len = strlen(s);
	// printf("%d\n",len );
	COLUMN = (int)ceil((float)len / ROW);
	printf("matrix %s\n",s );
	printf("cloumn %d\n",COLUMN);
	Encrypted_matrix = (char *)malloc( sizeof(char ));
	Matrix = (char **)calloc(ROW, sizeof(char *)); 
	for(i = 0; i < ROW; i++){ 
		Matrix[i] = (char *)calloc(COLUMN, sizeof(char)); 
	}

	/* Encryption is done here below */
	
	for(j = 0; j < COLUMN ; j++)
	{
		for(i = 0 ; i < ROW ; i++ )
		{
			if(c < len)
			{
				Matrix[i][j] =(s[c]);
				c = c + 1;
			}
			else
			{
				Matrix[i][j] = 'X';
				c = c + 1;
			}
		}
	}

	for(i = 0; i < ROW; i++){																		
		for(j = 0; j < COLUMN; j++){
			printf("%c 	",Matrix[i][j]);
		}
		printf("\n");
	}

	int t = 0;
	printf("Cypher text is \n");
	for ( i = 0; i < ROW; i++)
	{
		for(j = 0; j < COLUMN; j++)
		{
			Encrypted_matrix[t] = Matrix[i][j];
			t++;
		}
	}
	printf("\n");
return Encrypted_matrix;
/* Encryption is done upto this portion */

}

void decryption(char *s,int k){
	 // Decryption portion 
	int ROW, COLUMN,i,j, t = 0, len;
	char **Matrix;
	ROW = k;
	len = strlen(s);
	COLUMN = (int )ceil((float)len/ROW);

	Matrix = (char **)calloc(ROW, sizeof(char *));
	for(i = 0; i < ROW; i++){
		Matrix[i] = (char *)calloc(COLUMN, sizeof(char));
	}


	for(i = 0; i < ROW; i++){																		
		for(j = 0; j < COLUMN; j++){
		Matrix[i][j] = s[t++];
		}
	}

	for(j = 0; j < COLUMN; j++){
		for(i = 0; i < ROW; i++){
			printf("%c",Matrix[i][j] );
		}
	}
	printf("\n");
}