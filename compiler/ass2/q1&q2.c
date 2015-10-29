#include <stdio.h>
// #include <conio.h>

int ninputs;

int check(char,int ); //function declaration
int dfa[10][10],state[10];
char c[10], string[10];

int main()  
{
    int yn;
    int nstates, nfinals;
    int f[10];
    int i,j,flag=0,final=0;
    printf("enter the number of states that your dfa consist of \n");
    scanf("%d",&nstates);
    printf("%s\n", "enter the states : ");
    for(i = 0; i < nstates; i++){
      printf("\nenter state%d : ",i+1 );
      scanf("%d",&state[i]);
    }
    printf("enter the number of input symbol that dfa have \n");
    scanf("%d",&ninputs);
    printf("\nenter input symbols\t");

    char dummy;
    scanf("%c",&dummy);

    for(i=0; i<ninputs; i++) 
    {
     // printf("\n\n  input\t" );
     scanf("%c",&c[i]);
 }
//  while(ninputs >= 0){
//  printf("\n [%c]",c[ninputs] );
//  ninputs--;
// }

printf("[%c]\n",c[1] );
printf("[%c]\n",c[0] );


 printf("\n\nenter number of final states\t");
 scanf("%d",&nfinals);

 for(i=0;i<nfinals;i++)
 {
  printf("\n\nFinal state %d : q",i+1);
  scanf("%d",&f[i]);
}

printf("-----------------------------------------------------------------------");
printf("\n\ndefine transition rule as (initial state, input symbol ) = final state\n");

for(i=0; i<ninputs; i++)
{
  for(j=0; j<nstates; j++)
  {
     printf("\n(q%d , %c ) = q",j,c[i]);
     scanf("%d",&dfa[i][j]);
 }
}

printf("state \t");
for(i = 0; i < ninputs; i++){
  printf("%c\t",c[i] );
}
printf("\n");
for(i = 0; i < nstates; i++){
  printf("%d\t",state[i] );
  for(j = 0; j < ninputs; j++){
    printf("%d\t",dfa[j][i] );
  }
  printf("\n");
}


do
{
  int k=0;
  printf("\n\nEnter Input String.. ");
  scanf("%s",string);
  printf("%c\n",string[3 ] );
  while(string[k]!='\0'){
      if((flag =  check(string[k++],flag))<0)
          break;
      }
      for(i=0 ;i<nfinals ;i++)
          if(f[i] == flag )
              final= 1;
          else
              final = 0;
          if(final==1)
              printf("\n valid string"); 
          else
              printf("invalid string");
          

          printf("\nDo you want to continue.?  \n(y=1/n=0) \n ");
          scanf("%d",&yn);
          // yn = getchar();
          // if(yn == 'y')
          //   continue;
          // else
          //   break;
      }
      while(yn);

  }

  int check(char b,int d)
  {
   int j;
   for(j=0; j<ninputs; j++){
          if(b==c[j]){
               printf("%d\n",dfa[j][d] );
                return(dfa[j][d]);
           }
         }
       return -1;
   }