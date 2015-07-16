#include<stdio.h>
typedef struct ll
{
 int data;
 struct ll *next;
}node;


int main(void)
{
 int n=1,value,target,c=0;
 node *head=NULL;
 while(n)
  {
   printf("\npress 1 to create\n");
   printf("press 2 to search item\n");
   printf("Press 0 to exit\n");
   printf("enter your choice:");
   scanf("%d",&n);
   switch(n)
    {
     case 1:{
             printf("\nPlease enter a value:");
             scanf("%d",&value);
             CRET(&head,value);
             c++;
            }break;
     case 2:{
             TREV(head,c);
            }break;
    }
  }
}


void CRET(node **header,int value)
{
 node *current;
 if(*header==NULL)
  {
   (*header)=(node*)malloc(sizeof(node));
   (*header)->data=value;
   (*header)->next=NULL;
  }
 else
  {
   current=*header;
   while(current!=NULL)
    {
     if(current->next==NULL)
       {
        current->next=(node*)malloc(sizeof(node));
        current->next->data=value;
        current->next->next=NULL;
        current=NULL;
        return;
       }
     else
       current=current->next;
     }
  }
}

void TREV(node *header,int c)
{
 int ar[c],i=0,item,ind=-1;
 while(header!=NULL)
  {
     ar[i]=header->data;
     i++;   
     header=header->next;
   }
 printf("\nEnter the item to be searched:");
 scanf("%d",&item);
 ind=binsearch(ar,c,item);
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
