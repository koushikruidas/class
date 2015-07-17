#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
       int data;
       struct ll *next;
} node;
void inst(node **header,int v);
void delt(node **header,int t);
void disp(node *header);
int main(void)
{
       node *head='\0';
       int n=1,target,value;
       while(n)
       {
              printf("press 1 to insert an element\n");
              printf("press 2 to delete an element\n");
              printf("press 3 to display the linked list\n");
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
                     case 3:  disp(head);
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
              (*header)->next='\0';
              return;
       }
       node *prev,*current,*temp;
       prev=current=*header;
       while(current!='\0')
       {
              if(v<=(current)->data)
              {
                     break;
              }
              prev=current;
              current=current->next;
       }
       if(current=='\0')
       {
              prev->next=(node*)malloc(sizeof(node));
              prev->next->data=v;
              prev->next->next='\0';
              return;
       }
       if(v==current->data)
       {
              printf("duplicate value, enter another value\n");
              return;
       }
       if(current==*header)
       {
              temp=(node*)malloc(sizeof(node));
              temp->data=v;
              temp->next=current;
              *header=temp;
              return;
       }
       prev->next=(node*)malloc(sizeof(node));
       prev->next->data=v;
       prev->next->next=current;
       return;
}
void delt(node **header,int t)
{
       if(*header=='\0')
       {
              printf("linked list doesn't exist\n");
              return;
       }
       node *current,*prev;
       prev=current=*header;
       while(current!='\0')
       {
              if(current->data==t)
              {
                     break;
              }
              prev=current;
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
       prev->next=current->next;
       free(current);
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
