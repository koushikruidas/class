#include<stdio.h>

main()
{
 int ar[30],i,j,n,temp,min;
 printf("\nEnter the number of element:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
   {
    printf("\nEnter element %d :",i+1);
    scanf("%d",&ar[i]);
   }
 for(i=0;i<n-1;i++)
   {
    min=i;
    for(j=i+1;j<n;j++)
      {
       if(ar[min]>ar[j])
       min=j;
      }
    if(i!=min)
      {
       temp=ar[i];
       ar[i]=ar[min];
       ar[min]=temp;
      }
    }
printf("Sorted list is:");
for(i=0;i<n;i++)
 printf("%d ",ar[i]);
printf("\n");
}