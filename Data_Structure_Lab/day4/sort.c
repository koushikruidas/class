#include<stdio.h>
#include<stdlib.h>
void transfer(int *,int *,int *,int *,int *,int *,int *,int );
void display(int *,int *,int *,int *,int *,int *,int );
void scan(int *,int *,int *,int *,int *,int *,int *,int *,int );
void display1(int *,int *,int *,int );

int main()
{
int r1=-1,r2=-1,f1=0,f2=0,c1=0,c2=0,m=1,n,g,f=1;
ind:
printf("\n\nHow many digits you want to sort:");
scanf("%d",&n);
g=n;
if(n==0)
 {
  printf("\n\nYou have entered 0 !! please try again\n\n");
  goto ind;
 }
int cq1[n],cq2[n];
while(f)
 {
 printf("\nPress 1 to insert value to the first q\n");
 printf("press 2 to insert values to the second q\n");
 printf("Press 3 to redefine number of elements to be sorted\n");
 printf("Press 4 to stop\n");
 printf("Press 5 to pop values from the first q\n");
 printf("Press 6 to pop values from the second q\n");
 printf("Press 7 to see current stack values\n");
 printf("Enter your choice:");
 scanf("%d",&f);

 switch(f)
  {
   case 1:
     {
     if(g!=0) 
      {
      (r1)=(r1+1)%n;
      printf("\nEnter a desired value:");
      scanf("%d",&cq1[r1]);
      g--;
      c1++;
      printf("\n\nyou can enter %d more values\n\n",g);
      }
     }break;
   case 2:
    {
    if(g!=0)
      {
      r2=(r2+1)%n;
      printf("\nEnter a desired value:");
      scanf("%d",&cq2[r2]);
      g--;
      c2++;
      printf("\n\nyou can enter %d more values\n\n",g);
      }
    }break;
   case 3:
    {
     goto ind;
    }break; 
   case 4:
    {
    exit(1);
    }break;
   case 5:
    {
     if(c1==0)
      {
      printf("\n\nStack underflow\n\n");
      }
    else
      {
      printf("\n\nValue to be deleted %d",cq1[f1]);
      printf("\n\n");
      (f1)=(f1+1)%n;;
      g++;
      c1--;
      }
    }break;
  case 6:
   {
   if(c2==0)
      {
      printf("\n\nStack underflow\n\n");
      }
    else
      {
      printf("\n\nValue to be deleted %d",cq2[f2]);
      printf("\n\n");
      f1=(f1+1)%n;
      g++;
      c2--;
      }
   }break;
  case 7:
   {
     display(cq1,cq2,&f1,&f2,&c1,&c2,n);
   }break;
  }
  f=g;
 }

 
   transfer(cq1,cq2,&f2,&c2,&c1,&r1,&r2,n);
   display(cq1,cq2,&f1,&f2,&c1,&c2,n);
   scan(cq1,cq2,&f1,&f2,&r1,&r2,&c1,&c2,n);
   display1(cq2,&f2,&c2,n);

}

void display(int *cq1,int *cq2,int *f1,int *f2,int *c1,int *c2,int n)

{
  int i,j;
  if(*c1==0)
   {
    printf("\n1st Queue is empty!!");
    return;
   }
  else
   {
    printf("\nThe  first queue is:");
    for(i=(*f1),j=(*c1);i>0,j>0;i=(i+1)%n,j--)
      {
       printf("%d ",cq1[i]);
      }
    printf("\n");
   }
   if(*c2==0)
   {
    printf("\n2nd Queue is empty!!");
    return;
   }
  else
   {
    printf("\nThe  2nd queue is:");
    for(i=(*f2),j=(*c2);i<=n,j>0;i=(i+1)%n,j--)
      {
       printf("%d ",cq2[i]);
      }
    printf("\n");
   }
  
}

void transfer(int *cq1,int *cq2,int *f2,int *c2,int *c1,int *r1,int *r2,int n)
{
 int i,j;
 for(i=(*f2),j=(*c2);i>0,j>0;i=(i+1)%n,j--)
   {
   cq1[(*r1)=(*r1+1)%n]=cq2[i];
   (*c2)--;
   (*c1)++;
   }
 (*f2)=0;
 (*r2)=-1;
 (*c2)=0;
}

void scan(int *cq1,int *cq2,int *f1,int *f2,int *r1,int *r2,int *c1,int *c2,int n)
{
 int v,g,f,l,d=0,min,i,j,k,fst=0;
 min=cq1[0];
 while(*c2!=n)
  {
   min=cq1[*f1];
   l=0;
   for(i=(*f1),j=(*c1);i>0,j>0;)
      {
       if(min>cq1[i])
         {
          min=cq1[i];
          l=i;
          i=(i+1)%n;
          j--;
         }
       else
         {
          i=(i+1)%n;
          j--;
         }
      }
   while(l!=(*c1-1))
      {
       fst=cq1[*c1-1];
       for(k=*c1;k>0;k--)
          {
           cq1[k]=cq1[k-1];
          }
       l++;
       cq1[0]=fst;
      }
      *r2=(*r2+1)%n;
      cq2[*r2]=cq1[l];
      (*c2)++;
      (*c1)--;
  }
}

void display1(int *cq2,int *f2,int *c2,int n)
{
int i,j;

   
  
    printf("\nThe sorted queue is:");
    for(i=(*f2),j=(*c2);i<=n,j>0;i=(i+1)%n,j--)
      {
       printf("%d ",cq2[i]);
      }
    printf("\n");
   
}
