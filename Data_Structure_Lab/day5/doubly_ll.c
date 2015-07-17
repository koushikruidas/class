#include<stdio.h>
#include<stdlib.h>
typedef struct dll
{
       int data;
       struct dll *prev,*next;
}node;
void inst(node **header,int v);
void delt(node **header,int t);
void instbef(node **header,int t,int v);
void instaft(node **header,int t,int v);
void disp(node *header);
int main(void)
{
       node *head='\0';
       int n=1,target,value;
       while(n)
       {
              printf("press 1 to insert an element\n");
              printf("press 2 to delete an element\n");
              printf("press 3 to insert before an element\n");
              printf("press 4 to insert after an element\n");
              printf("press 5 to display the linked list\n");
              printf("press 0 to exit\n");
              scanf("%d",&n);
              switch(n)
              {
                     case 1:  printf("enter the value to be inserted\n");
                                   scanf("%d",&value);
                                   inst(&head,value);
                     break;
                     case 2:  printf("enter the value to be deleted\n");
                                   scanf("%d",&target);
                                   delt(&head,target);
                     break;
                     case 3:  printf("enter the target element\n");
                                   scanf("%d",&target);
                                   printf("enter the element to be inserted\n");
                                   scanf("%d",&value);
                                   instbef(&head,target,value);
                     break;
                     case 4:  printf("enter the target element\n");
                                   scanf("%d",&target);
                                   printf("enter the element to be inserted\n");
                                   scanf("%d",&value);
                                   instaft(&head,target,value);
                     break;
                     case 5:  disp(head);
                     break;
              }
       }
}
void inst(node **header,int v)
{
       if(*header=='\0')
       {
              *header=(node*)malloc(sizeof(node));
              (*header)->data=v;
              (*header)->next=(*header)->prev='\0';
              return;
       }
       node *current=*header;
       while(current->next!='\0')
       {
              current=current->next;
       }
       current->next=(node*)malloc(sizeof(node));
       current->next->data=v;
       current->next->next='\0';
       current->next->prev=current;
       return;
}
void delt(node **header,int t)
{
       if(*header=='\0')
       {
              printf("linked list doesn't exist\n");
              return;
       }
       node *current;
       current=*header;
       while(current!='\0')
       {
              if(current->data==t)
              {
                     break;
              }
              current=current->next;
       }
       if(current=='\0')
       {
              printf("target not found\n");
              return;
       }
       if(current==*header)
       {
              *header=current->next;
              free(current);
              return;
       }
       current->prev->next=current->next;
       free(current);
       return;
}
void instbef(node **header,int t,int v)
{
       if(*header=='\0')
       {
              printf("linked list doesn't exist\n");
              return;
       }
       node *current=*header,*temp;
       while(current!='\0')
       {
              if(current->data==t)
              {
                     break;
              }
              current=current->next;
       }
       if(current=='\0')
       {
              printf("target not found\n");
              return;
       }
       if(current==*header)
       {
              temp=(node*)malloc(sizeof(node));
              temp->data=v;
              temp->prev='\0';
              temp->next=current;
              *header=temp;
              current->prev=temp;
              return;
       }
       temp=(node*)malloc(sizeof(node));
       temp->data=v;
       temp->next=current;
       temp->prev=current->prev;
       current->prev->next=temp;
       current->prev=temp;
       return;
}
void instaft(node **header,int t,int v)
{
       if(*header=='\0')
       {
              printf("linked list doesn't exist\n");
              return;
       }
       node *current=*header,*temp;
       while(current!='\0')
       {
              if(current->data==t)
              {
                     break;
              }
              current=current->next;
       }
       if(current=='\0')
       {
              printf("target not found\n");
              return;
       }
       temp=(node*)malloc(sizeof(node));
       temp->data=v;
       temp->prev=current;
       temp->next=current->next;
       current->next=temp;
       if(temp->next=='\0')
              return;
       temp->next->prev=temp;
       return;
}
void disp(node *header)
{
       if(header=='\0')
       {
              printf("linked list doesn't exist\n");
              return;
       }
       node *current=header;
       printf("Head--->");
       while(current!='\0')
       {
              printf("%d--->",current->data);
              current=current->next;
       }
       printf("null\n");
       return;
}
