#include<stdio.h>
#include<stdlib.h>
typedef struct cll
{
	int data;
	struct cll *next;
}node;
void create(node **header,int v,int *c);
void delete(node **header,int t,int *c);
void display(node **header,int c);
void cnt(node **header);
int main(void)
{
	int n=1,count=0,value,target;
	node *head=NULL;
	while(n)
	{
		printf("press 1 to create\n");
		printf("press 2 to delete\n");
		printf("press 3 to display the linked list\n");
		printf("press 4 to show the number of elements\n");
		printf("press 0 to exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("enter the value to be inserted\n");
				scanf("%d",&value);
				create(&head,value,&count);
			break;
			case 2: printf("enter the value to be deleted\n");
				scanf("%d",&target);
				delete(&head,target,&count);
			break;
			case 3: display(&head,count);
			break;
			case 4: cnt(&head);
			break;
		}
	}
}
void create(node **header,int v,int *c)
{
	if(*header==NULL)
	{
		(*header)=(node*)malloc(sizeof(node));
		(*header)->data=v;
		(*header)->next=*header;
		(*c)++;
	}
	else
	{
		int i;
		node *current=*header;
		for(i=1;i<(*c);i++)
		{
			current=current->next;
		}
		current->next=(node*)malloc(sizeof(node));
		current->next->data=v;
		current->next->next=(*header);
		(*c)++;
	
	}
	return;
}
void delete(node **header,int t,int *c)
{
	if(*header==NULL)
	{
		printf("linked list doesn't exist\n");
		return;
	}
	node *current,*prev;
	current=prev=*header;
	int i=1;
	for(i=1;i<=(*c);i++)
	{
		if(current->data==t)
		{
			break;
		}
		if(i==(*c))
			continue;
		current=current->next;
		if(i==1)
			continue;
		prev=prev->next;
	}
	if(i>(*c))
	{
		printf("target not found\n");
		return;
	}
	if(*c==1)
	{
		*header=NULL;
		(*c)--;
		return;
	}
	else
	{	
		if(current==*header)
		{
			node *current1=*header;
			*header=current->next;
			while(current1->next!=current)
			{
				current1=current1->next;
			}
			current1->next=*header;
		}
		else
			prev->next=current->next;
	}
	(*c)--;
	free(current);
	return;
}
void display(node **header,int c)
{
	if(*header== NULL)
	{
		printf("linked list does not exist\n");
		return;
	}
	node *current=*header;
	int i;
	printf("Head---->");
	for(i=1;i<=c;i++)
	{
		printf(" %d---->",current->data);
		current=current->next;
	}
	printf("Head\n");
	return;
}
void cnt(node **header)
{
	if(*header==NULL)
	{
		printf("count= 0\n");
		return;
	}
	int c=1;
	node *current=(*header)->next;
	while(current!=*header)
	{
		c++;
		current=current->next;
	}
	printf("count= %d\n",c);
	return;
}	
