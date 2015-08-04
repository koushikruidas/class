#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int mat[5][5], a[26] = {0};
	int ii,jj,kk;
	int *pmat;
	char *pa;

	pmat =(int *) mat;
	pa = (char *)argv[1];

	while(*pa){
		if(a[*pa - 'A'] != 1 && *pa != 'J'){
			a[*pa - 'A'] = 1;
			*pmat = *pa;
			*pmat++;
		}
		*pa++;
	}

	for(ii = 0 ; ii < 26; ii++){
		if(a[ii] == 0 && ('A' + ii) != 'J'){
			*pmat = ('A' + ii);
			*pmat++;
		}
	}

	for(ii = 0; ii < 5; ii++){
		for(jj = 0; jj < 5; jj++){
			printf("[%c]	",mat[ii][jj] );
		}
		printf("\n");
	}
	return 0;
}