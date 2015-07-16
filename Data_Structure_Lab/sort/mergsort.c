#include<stdio.h>
//void mergsort(int,int,int);
//void merg(int,int,int,int,int,int);
//void copy(int,int,int,int);

main()
{
int i,n,ar[20];
printf("Enter the number of element:");
scanf("%d",&n);
 for(i=0;i<n;i++)
   {
    printf("Enter element %d:",i+1);
    scanf("%d",&ar[i]);
   }
 mergsort(ar,0,n-1);
 printf("\nSorted list is:");
 for(i=0;i<n;i++)
   printf("%d ",ar[i]);
}

void mergsort(int ar[],int low,int up)
{
  int mid;
  int temp[20];
  if(low<up)
   {
    mid=(low+up)/2;
    mergsort(ar,low,mid);
    mergsort(ar,mid+1,up);
    merg(ar,temp,low,mid,mid+1,up);
    copy(ar,temp,low,up);
   }
}
void merg(int ar[],int temp[],int low1,int up1,int low2,int up2)
{
 int i=low1;
 int j=low2;
 int k=low1;
 while((i<=up1)&&(j<=up2))
   {
    if(ar[i]<=ar[j])
      temp[k++]=ar[i++];
    else
      temp[k++]=ar[j++];
   }
 while(i<=up1)
   temp[k++]=ar[i++];
 while(j<=up2)
   temp[k++]=ar[j++];
}

void copy(int ar[],int temp[],int low,int up)
{
 int i;
 for(i=low;i<=up;i++)
   ar[i]=temp[i];
}