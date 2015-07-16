#include<stdio.h>

main()
{
 int i,size,item,ar[20],ind=-1;
 printf("\nEnter the number of element:");
 scanf("%d",&size);
 printf("\nEnter the element in sorted order:");
 for(i=0;i<size;i++)
   scanf("%d",&ar[i]);
 printf("\nEnter the item to be searched:");
 scanf("%d",&item);
 ind=binsearch(ar,size,item);
 if(ind==-1)
  printf("\n%d not found in array\n",item);
 else
  printf("\n%d found at position %d\n",item,(ind+1));
}

int binsearch(int ar[],int size,int item)
 {
  int low=0,up=size-1,mid;
 while(low<=up)
    {
     mid=(low+up)/2;
     if(item>ar[mid])
       low=mid+1;
     else if(item<ar[mid])
       up=mid-1;
     else
       return mid;
    }
    return -1;
}