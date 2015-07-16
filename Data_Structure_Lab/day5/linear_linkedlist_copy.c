/* @###############implement of linear linkedlist ###############@*/
#include<stdio.h>
#include<malloc.h>

/*@############### struct function #################@*/

typedef struct data
{
	int data;
	struct data *next;
}node;

/* ################ function protocal ################@ */

void inst(node **,int );
void del(node **, int );
void trav(node **,node **);

/* ############### maihn function ################## */

int main(void)
{
	node *head = NULL, *count = NULL;
	int n = 1, value,target;
	while(n)
	{
		printf("\n##1::- insert\n##2::-deletion\n##3::- traverse\n##0::- stop\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("enter value::-");
				scanf("%d",&value);
				inst(&head,value);
				break;
			case 2: printf("enter the target u want to delet::-");
				scanf("%d",&target);
				del(&count,target);
				break;
			case 3: trav(&head,&count);
				break;
		}
	}
	return 0;
}

/* ############## insert function ############# */

void inst(node **head, int value) 
{
	node *current;
	if((*head) == NULL)
	{
		(*head) = (node*)malloc(sizeof(node));
		(*head) -> data = value;
		(*head) -> next = NULL;
	}
	else
	{
		current = *head;
		while(current !=NULL)
		{
			if(current -> next == NULL)
			{
				current -> next = (node*)malloc(sizeof(node));
				current -> next -> data = value;
				current -> next -> next = NULL;
				current = current -> next;
				return ;
			}
			else
			{
				current = current -> next;
			}  
		}
	}
}

/* ############### traverse function ############### */
void trav(node **head,node **count)
{
	(*count) = (*head);
	printf("[HEAD]--->");
	while((*head) != NULL)
	{
		printf("[%d]--->",(*head) -> data);
		(*head) = (*head) -> next;
	}
	printf("[NULL]\n"); 	
}

/* ################ deletion function ################# */

void del(node **count,int target)
{
	node *current;
	if((*count) == NULL)
	{
		printf("no linked_list available\n");
		return ;
	}
	else
	{
		current = (*count);
		while(current -> next != NULL)
		{
			if(current -> data == target)
			{
				printf("target found\n");
				current = current -> next ->next;
			}
			else
			{
				break;
			}
			if(current == NULL)
			{
				printf("data not found\n");
				return ;
			}
		}
	}
}
