#include<stdio.h>

typedef struct bs
{
	int key;
	struct bs *left;
	struct bs *right;
}node;

main()
{
	int a,val=0;
	node *head,*left,*right;
	while(1)
	{
		printf("Enter 1 to Insert.\n");
		printf("Enter 2 to Delete.\n");
		printf("Enter 3 to Display in In-order.\n");
		printf("Enter 0 to Exit.\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: printf("Enter a value:\n");
				scanf("%d",&val);
				INS(&head,val);
			break;
			case 2: printf("Enter the value to delete:\n");
				scanf("%d",&val);
				//del(&head,val);
			break;
			case 3: disp(head);
			break;
			case 0: exit(0);
			break;
			default : printf("Enter a valid choice!\n");
		}
	}
}

void INS(node **header, int val)
{
	if(*header==NULL)
	{
		*header=(node*)malloc(sizeof(node));
		(*header)->key=val;
		(*header)->left=(*header)->right=NULL;
	}
	else if(((*header)->key)>val)
		INS((&(*header)->left),val);
	else if(((*header)->key)<val)
		INS((&(*header)->right),val);
	else
		printf("Duplicate value..!\n");
}




//void del(node **head, int val);




void disp(node *head)
{
	if(head==NULL)
	{
		printf("Tree does not exist..!\n");
		return;
	}
	if(head->left!=NULL)
	disp(head->left);
	printf("%d\n",head->key);
	if(head->right!=NULL)
	disp(head->right);
}
