#include<stdio.h>
#include<stdlib.h>
typedef struct dll
{
       int data;
       struct dll *prev,*next;
}node;
void inst(node **header,int v,int *c);
void delt(node **header,int *c);
void disp(node *header,int c);
int main(void)
{
       node *head='\0';
       int n=1,count=0,target,value;
       while(n)
       {
              printf("press 1 to insert an element into the queue\n");
              printf("press 2 to delete an element from the queue\n");
              printf("press 3 to display the queue\n");
              printf("press 0 to exit\n");
              scanf("%d",&n);
              switch(n)
              {
                     case 1:  printf("enter the value to be inserted\n");
                                   scanf("%d",&value);
                                   inst(&head,value,&count);
                     break;
                     case 2:  delt(&head,&count);
                     break;
                     case 3:  disp(head,count);
                     break;
              }
       }
}
void inst(node **header,int v,int *c)
{
       if(*header=='\0')
       {
              *header=(node*)malloc(sizeof(node));
              (*header)->data=v;
              (*header)->next=(*header)->prev=*header;
              (*c)++;
              return;
       }
       int i;
       node *current=*header;
       for(i=1;i<(*c);i++)
       {
              current=current->next;
       }
       current->next=(node*)malloc(sizeof(node));
       current->next->data=v;
       current->next->prev=current;
       current->next->next=*header;
       (*header)->prev=current->next;
       (*c)++;
       return;
}
void delt(node **header,int *c)
{
       if(*header=='\0')
       {
              printf("queue is empty\n");
              return;
       }
       printf("the deleted element is %d\n",(*header)->data);
       if(*c==1)
       {
              *header='\0';
              (*c)--;
              return;
       }
       (*header)->next->prev=(*header)->prev;
       (*header)->prev->next=(*header)->next;
       (*header)=(*header)->next;
       (*c)--;
       return;
}
void disp(node *header,int c)
{
       if(header=='\0')
       {
              printf("queue is empty\n");
              return;
       }
       int i;
       printf("front--->");
       node *current=header;
       for(i=1;i<=c;i++)
       {
              printf("%d--->",current->data);
              current=current->next;
       }
       printf("rear\n");
       return;
}
