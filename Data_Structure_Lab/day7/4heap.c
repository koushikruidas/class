#include<stdio.h>

int c=0;

int main()
{
	 int n=1,val=0,t=0,size=0,fs=0,d;
	 int heap[100];
	 while(n)
	  {
	   printf("\n\nTo Insert value press 1");
	   printf("\nTo traverse press 2");
	   printf("\nTo delete press 3");
	   printf("\nTo see the sorted list after deletion press 4");
	   printf("\nPress 0 to exit");
	   printf("\nEnter your choice:");
	   scanf("%d",&n);
	   switch(n)
	     {
	      case 1:
		     {
		      printf("\nPlease enter a value:");
		      scanf("%d",&val);
		      CRET(heap,val,&size);
		      fs=size;
		     }break;
	      case 2:
		     {
		      printf("\nThe HEAP condition is:\n");
		      TREV(heap,&size);
		     }break;
	      case 3:
		     {
		      printf("\nValue deleted:");
		      d=DEL(heap,&size);
		      printf("%d",d);
		     }break;
	      case 4:
		     {
		      printf("\nSorted values after deletion:\n");
		      TREV1(heap,fs,&size);
		     }break;
	     }
	   }
}

int CRET(int *t,int key,int *sz)
{
	 int k=0,par,i=0;
	 (*sz)++;
	 t[*sz]=key;
	 i=(*sz);
	 k=t[i];
	 par=i/2;
	 while(t[par]<k && par>=1)
	   {
	    t[i]=t[par];
	    i=par;
	    par=i/2;
	   }
	 t[i]=k;
}

int TREV(int *t,int *sz)
{
	int i;
	 if(*sz==0)
	  {
	   printf("\nHeap EMPTY\n");
	   return;
	  }
	 for(i=1;i<=(*sz);i++)
	   {
	    printf("%d ",t[i]);
	   }
}

int DEL(int *t,int *sz)
{
	 int d,j=1,lc,rc,num,fs;
	 d=t[1];
	 t[1]=t[*sz];
	 t[*sz]=d;
	 (*sz)--;
	 lc=2*j;
	 rc=lc+1;
	 num=t[j];
	 while(rc<=*sz)
	   {
	    if(num>=t[rc] && num>=t[lc])
	      {
	       t[j]=num;
	       return d;
	      }
	    else if(t[lc]>t[rc])
	      {
	       t[j]=t[lc];
	       
	       j=lc;
	      }
	    else
	      {
	       t[j]=t[rc];
	       j=rc;
	      }
	    lc=2*j;
	    rc=lc+1;
	   }
	 if(lc==*sz && num<t[lc])
	  {
	   t[j]=t[lc];
	   j=lc;
	  }
	 t[j]=num;
	 return d;
}

int TREV1(int *t,int fs,int *sz)
{
	 int i,j;
	 j=fs;
	 i=fs-(*sz);
	 if(i==0)
	  {
	   printf("\nHeap not sorted\n");
	   return;
	  }
	 while(i>0)
	   {
	    printf("%d ",t[j]);
	    j--;
	    i--;
	   }
}
