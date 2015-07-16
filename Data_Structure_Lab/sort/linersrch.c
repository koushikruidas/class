#include<stdio.h>
typedef struct ll
{
 int data;
 struct ll *next;
}node;


int main(void)
{
 int n=1,value,target;
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
            }break;
     case 2:{
             TREV(head);
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

void TREV(node *header)
{
 int s,i=0,f=1;
 printf("\nEnter the item,to be searched:");
 scanf("%d",&s);
 //printf("HEAD---->");
 while(header!=NULL)
  {
   ++i;
   if(header->data==s)
    {
     printf("\nThe item %d found at position %d\n",header->data,i);
     f=0;
     break;
    }
   header=header->next;
  }
 if(f!=0)
   printf("\nThe specified item is not in the list.\n");
 return ;
}
