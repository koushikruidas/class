#include<stdio.h>

main()
{
 int ar[30],i,j,k,n;
 printf("Enter the number of element:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
   {
    printf("\nEnter element %d :",i+1);
    scanf("%d",&ar[i]);
   }
 for(i=1;i<n;i++)
   {
    k=ar[i];
    for(j=i-1;j>=0 && k<ar[j];j--)
       ar[j+1]=ar[j];
    ar[j+1]=k;
   }
 printf("\nSorted list:");
 for(i=0;i<n;i++)
   printf("%d ",ar[i]);
 printf("\n");
}