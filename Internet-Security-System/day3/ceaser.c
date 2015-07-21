#include <stdio.h>


int main(void){

    int i=0,j=0;
    int c;
    int store[26] = {0};
    int count[26] = {0};
    // char *temp,*arr;
    int temp,arr;
    FILE *fp;
    fp = fopen("input.txt","r");
    while((c = fgetc(fp)) != EOF){

        // printf("%c-", c);
        temp  = c - 'a';
        ++store[temp];
        arr = (temp + 7)%26;
        ++count[arr];
        // printf("%c ", arr + 'a');

    }

    for(i=0;i<26;i++){

        printf(" %c : ",(i + 'a'));
        for(j=0;j<store[i];j++){

            printf("+");
        }
        printf("\n");
    }
    printf("Frequency in cypher text : \n");
    for(i=0;i<26;i++){

        printf("%c : ",(i + 'a'));
        for(j=0;j<count[i];j++){

            printf("*");
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}