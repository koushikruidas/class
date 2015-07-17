#include<stdio.h>

typedef struct bintree
{
struct bintree *left,*right;
int key;
}bst;

int main()
{
	 int n=1,val=0,t=0,vl=0;
	 bst *head=NULL;
	 while(n)
	  {
	   printf("\n\nTo Insert value press 1");
	   printf("\nPre-order traversal press 2");
	   printf("\nIn-order traversal press 3");
	   printf("\nPost-order traversal press 4");
	   printf("\nTo delete press 5");
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
	      case 5:
		    {
		     printf("\nType in the value which you want to delete:");
		     scanf("%d",&vl);
		     DEL(&head,vl);
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
	    (*header)->left=(*header)->right=NULL;
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

void DEL(bst **header,int value)
{
	 bst *temp,*succ;
	 if(*header==NULL)
	   {
	    printf("\nValue not found");
	    return(*header);
	   }
	 if(value<(*header)->key)
	   DEL((&(*header)->left),value);
	 else if(value>(*header)->key)
	   DEL((&(*header)->right),value);
	 else
	  {
	    if((*header)->left!=NULL && (*header)->right!=NULL)
	      {
	       succ=(*header)->right;
	       while(succ->left!=NULL)
		  succ=succ->left;
	       (*header)->key=succ->key;
		DEL((&(*header)->right),succ->key);
	      }
	    else
	      {
	       temp=(*header);
	       if((*header)->left!=NULL)
		  (*header)=(*header)->left;
	       else if((*header)->right!=NULL)
		  (*header)=(*header)->right;
	       else
		  (*header)=NULL;
	       free(temp);
	      }
	  }
	  return((*header));
}
