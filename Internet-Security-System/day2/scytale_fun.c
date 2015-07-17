#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void encryption(char *,char **,int ,int );
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
	COLUMN = (len / ROW);
	Encrypted_matrix = (char **)calloc(ROW, sizeof(char *));
	Matrix = (char **)calloc(ROW, sizeof(char *)); 
	for(i = 0; i < ROW; i++){ 
		Matrix[i] = (char *)calloc(COLUMN, sizeof(char)); 
		Encrypted_matrix[i] = (char *)calloc(COLUMN, sizeof(char));
	}

	encryption(str,Matrix,ROW,COLUMN);
	return 0;
}

void encryption(char *a, char **b,int r, int c){

	int i,j, k = 0;
	for(j = 0; j < c; j++){
		for(i = 0; i < r; i++){
			b[i][j] = a[k++];
		}
	}

	for(i = 0; i < r; i++){																		
		for(j = 0; j < c; j++){
			printf("%c 	",b[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < r; i++){																		
		for(j = 0; j < c; j++){
			// Encrypted_matrix[i][j] = Matrix[i][j];
			printf("%c", b[i][j]);
		}
	}
	printf("\n");

}