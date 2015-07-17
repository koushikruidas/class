/* ################## implementation of binary search tree ################### */

#include<stdio.h>
#include<malloc.h>

/* ################ structuture decleration #################### */

typedef struct node
{
	struct node *left, *right;
	int key;
}bst;

/* ############### declerations of the functions ################ */

void inst(bst **, int );
void del(bst **);		
void traverse(bst **);
void del1(bst **);	

/* ############## main function ################ */

int main(void)
{
	bst *head;
	int value,target,n=1;
	while(n)
	{
		printf("##:-1 insert\n##2:-delection\n##3:-traverse\n##:-0 exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("enter d value u want to insert\n");
			        scanf("%d",&value);
			        inst(&head,value);
			        break;
			case 2: printf("enter d value u want to delete\n");
			        scanf("%d",&target);
			        del(&head,target);
			        break;		
			case 3: traverse(&head);
			        break;		
		}	
	}
	return ;
}

/* ############### implementation of insert function ############### */

void inst(bst **head,int value)
{
	if((*head) == NULL)
	{
		(*head) = (bst*)malloc(sizeof(bst));
		(*head) -> key = value;
		(*head) -> left = NULL;
		(*head) -> right = NULL;
	}
	else
	{
		if((*head) -> key > value)
		{
			inst(&((*head) -> left) , value);
		}
		else if((*head) -> key < value)
		{
			inst(&((*head) -> right) , value);
		}
		else
		{
			printf("duplicate value\n");
		}
	}
}

/* ############### implementation of traversal function ################ */

void traverse(bst **head)
{
	if((*head) == NULL)
	{
		return ;
	
	}
	if(((*head) -> left) != NULL)
	{
		traverse(&((*head) -> left));
	}
	printf("[%d]-->",((*head) -> key));
	if(((*head) -> right) != NULL)
	{
		traverse(&((*head) -> right));
	}
}

/* ################ deletion function ################## */

void del(bst **head,int target)
{
	int i = (*head);
	while(i !=NULL)
	{
		if(((*head) -> left -> key) == target)
		{
			del1(&((*head) -> left));
			
		}
		if(((*head) -> right -> key) == target)
		{
			del1(&((*head) -> right));
		}
		if(((*head) -> key) == target)
		{
			del1(&(head));
		}
	}
}

/* ################ del1 function ################## */

void del1(bst **head)
{
	if(((*head) -> left) == NULL)
	{
		(*head) -> left) = ((*head) -> left -> right);
	}
}
