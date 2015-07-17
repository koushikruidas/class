#include<stdio.h>

typedef struct bintree
{
struct bintree *left,*right;
int key;
}bst;

int top=-1;
int *stk[50];

int main()
{
	 int n=1,val=0,t=0,vl=0;
	 bst *head=NULL;
	 while(n)
	  {
	   printf("\n\nTo Insert value press 1");
	   printf("\nPre-order traversal press 2");
	   printf("\nTo delete press 3");
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
	  int itm=0;
	  bst *current;
	  current=header;
	  if(current==NULL)
	   {
	    printf("\nTree empty");
	    return;
	   }
	  PUSH(current);
	  while(EMPTY()!=1)
	    {
	     current=POP();
	     printf("%d ",current->key);
	     if(current->right!=NULL)
	       PUSH(current->right);
	     if(current->left!=NULL)
	       PUSH(current->left);
	    }
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

void PUSH(int *addr)
{
	 top=top+1;
	 stk[top]=addr;
	 return;
}

POP()
{
	int *itm;
	itm=stk[top];
	top--;
	return itm;
}

int EMPTY()
{
	if(top==-1)
	  return 1;
	else
	  return 0;
}
