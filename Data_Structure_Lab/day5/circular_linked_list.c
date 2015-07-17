/* ############ implement of circular link list ############# */

#include<stdio.h>
#include<malloc.h>

/* ########## structure decleration ############ */

typedef struct link_list
{
	int data;
	struct link_list *next;
}node;

/* ########### define the functions ############### */

void crete(node **,int ,int *);

//void del();
void disp(node **,int *);

/* ########## implementation of main function ########### */

int main(void)
{
	int n = 1,value,target,count = 0;
	node *head = NULL; /* ######### value of the header ########## */
	while(n)
	{
		printf("\n##1:-insert\n##2:-delete\n##3:-display\n##0:-return\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("enter the value u want to insret\n");
			        scanf("%d",&value);
			        crete(&head,value,&count);
			        break;
		/*
			case 2: printf("enter the value u wnat to delete\n");
			        scanf("%d",&target);
			        del(&head,target);
			        break;*/
			case 3: disp(&head,&count);
			        break;
	       }
	}
		return 0;
}

/* ########## implementation of crete function ############ */

void crete(node **head, int value,int *count)
{
	int i;
	node *current;
	current = (*head);

	if(*(count) == 0)
	{
		(*head) =(node*)malloc(sizeof(node));
		(*head) -> data= value;
		(*head) -> next = (*head);
		(*count)++;
	}
	else
	{
		i = (*count);
		while(i>1)
		{
			if(current == (*head))
			{
				current -> next = (node*)malloc(sizeof(node));
				current -> next -> data = value;
				current -> next -> next = (*head);
				current = current -> next;
				(*count)++;
				return ;
			}
			else
			{
				current = current -> next;
			}
		}
	}
}

/* ########## implementation of  display function ########## */

void disp(node **head, int *count)
{
	node *current = *head;
	printf("[HEAD]--->");
	while((*count)>=0)
	{
		printf("[%d]--->",(current) -> data);
		(current) = (current) -> next;
		(*count)--;
	}
	printf("[TAIL]\n");
}
