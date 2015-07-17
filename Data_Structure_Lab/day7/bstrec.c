#include<stdio.h>

typedef struct bintree
{
struct bintree *left,*right;
int key;
}bst;

int main()
{
	 int n=1,val=0,t=0;
	 bst *head=NULL;
	 while(n)
	  {
	   printf("\n\nTo Insert value press 1");
	   printf("\nPre-order traversal press 2");
	   printf("\nIn-order traversal press 3");
	   printf("\nPost-order traversal press 4");
	   printf("\nPress 0 to exit");
	   printf("\nEnter your choice:");
	   scanf("%d",&n);
	   switch(n)
	     {
	      case 1:
		     {
		      printf("\nPlease enter a value:");
		      scanf("%d",&val);
		      CRET(&head,val);
		     }break;
	      case 2:
		     {
		      printf("\nThe tree in PRE-ORDER TRAVERSAL IS:\n");
		      PRETREV(head);
		     }break;
	      case 3:
		     {
		      printf("\nThe tree in IN-ORDER TRAVERSAL IS:\n");
		      INTREV(head);
		     }break;
	      case 4:
		    {
		     printf("\nThe tree in POST-ORDER TRAVERSAL IS:\n");
		     POSTREV(head);
		    }break;
	     }
	   }
}


void CRET(bst **header,int value)
{
	 if(*header==NULL)
	   {
	    *header=(bst*)malloc(sizeof(bst));
	    (*header)->key=value;
	    (*header)->left=NULL;
	    (*header)->right=NULL;
	   }
	 else
	   {
	    if((*header)->key>value)
	      CRET(&((*header)->left),value);
	    else if((*header)->key<value)
	      CRET(&((*header)->right),value);
	    else
	      printf("\nDuplicate values");
	   }
}

void PRETREV(bst *header)
{
	  if(header==NULL)
	   return;
	  printf(" [%d] ",header->key);
	  if(header->left!=NULL)
	   PRETREV(header->left);
	  if(header->right!=NULL)
	   PRETREV(header->right);
}

void INTREV(bst *header)
{
	  if(header==NULL)
	   return;
	  if(header->left!=NULL)
	   INTREV(header->left); 
	  printf(" [%d] ",header->key);
	  if(header->right!=NULL)
	   INTREV(header->right);
}

void POSTREV(bst *header)
{
	  if(header==NULL)
	   return;
	  if(header->left!=NULL)
	   POSTREV(header->left); 
	  if(header->right!=NULL)
	   POSTREV(header->right);
	  printf(" [%d] ",header->key);
}
