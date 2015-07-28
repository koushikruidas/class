#include <stdio.h>
#include <stdlib.h>


int main (){
	FILE *fp;
	char img_name[35] ,charc[25], *lineptr;
	int i, j,x;
	int ROW,COLUMN, MIN;
	size_t k = 200;
	char **Matrix; 


	printf("%s\n", "Enter the Image name u want :");
	scanf("%s",img_name);

	fp = fopen(img_name,"r");

	if(fp == NULL){
		perror("Error while opening the file : ");
		return -1;
	}

	printf("The contents of %s file are :\n", img_name);

	// buf = (int*)malloc(n* sizeof(int)); 
	lineptr = (char *)malloc(  sizeof(char));	 	

	fscanf(fp,"%s\n",charc);
	printf("%s\n",charc);

	getline(&lineptr,&k,fp);	
	printf("%s \n", lineptr);

	fscanf(fp,"%d %d %d",&ROW,&COLUMN,&MIN);
	printf("%d	%d	%d\n",ROW,COLUMN,MIN );

	
	Matrix = (char **)calloc(ROW, sizeof(char *)); 
	for(i = 0; i < ROW; i++){ 
		Matrix[i] = (char *)calloc(COLUMN, sizeof(char)); 
	}

	for(i = 0 ; i <ROW; i++){
		for(j = 0; j < COLUMN; j++){
			fscanf (fp,"%c",&x);
			Matrix[i][j] = x ;
		}
	}

	for(i = 0 ; i <100; i++){
		for(j = 0; j < 100; j++){
			printf("%c",Matrix[i][j] );
		}
		// printf("\n");
	}

	fclose(fp);
	return 0;
}