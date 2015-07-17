#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char **Matrix, **Encrypted_matrix ;
	char str[100]; 
	int ROW, COLUMN, i, len, j, k = 0;
	printf("%s\n", "enter a string");
	fgets(str,100,stdin);
	printf("%s\n", "enter the #Row  and #COLUMN");
	scanf("%d", &ROW);
	len = strlen(str);
	// printf("%d\n",len );
	COLUMN = len / ROW;
	Encrypted_matrix = (char **)calloc(ROW, sizeof(char *));
	Matrix = (char **)calloc(ROW, sizeof(char *)); 
	for(i = 0; i < ROW; i++){ 
		Matrix[i] = (char *)calloc(COLUMN, sizeof(char)); 
		Encrypted_matrix[i] = (char *)calloc(COLUMN, sizeof(char));
	}
/* Encryption is done here below */
	for(j = 0; j < COLUMN; j++){
		for(i = 0; i < ROW; i++){
			Matrix[i][j] = str[k++];
		}
	}

	for(i = 0; i < ROW; i++){																		
		for(j = 0; j < COLUMN; j++){
			printf("%c 	",Matrix[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < ROW; i++){																		
		for(j = 0; j < COLUMN; j++){
			Encrypted_matrix[i][j] = Matrix[i][j];
			printf("%c", Matrix[i][j]);
		}
	}
	printf("\n");

/* Encryption is done upto this portion */

/* Decryption portion */

	for(j = 0; j < COLUMN; j++){																		
		for(i = 0; i < ROW; i++){
			printf("%c",Encrypted_matrix[i][j] );
		}
	}
	printf("\n");
}