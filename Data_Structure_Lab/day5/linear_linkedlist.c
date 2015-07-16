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
//void del(node **);
void trav(node **);

/* ############### maihn function ################## */

int main(void)
{
	node *head = NULL;
	int n = 1, value;
	while(n)
	{
		printf("\n##1::- insert\n##2::-deletion\n##3::- traverse\n##4::- stop\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("enter value::-");
				scanf("%d",&value);
				inst(&head,value);
				break;
		/*	case 2: del();
				break;*/
			case 3: trav(&head);
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
void trav(node **head)
{
	printf("[HEAD]--->");
	while((*head) != NULL)
	{
		printf("[%d]--->",(*head) -> data);
		(*head) = (*head) -> next;
	}
	printf("[NULL]\n"); 	
}	
