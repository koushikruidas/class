#include<stdio.h>
#include<string.h>
#define SIZE 5
/*##################declearing structure###########################*/

struct data
{
	char name[25];
	int prio;
};
/*################ defining functions ###########################*/

void inste(struct data *,int *);
void del(struct data *,int *,int *);
//void disp(struct data *,int *,int *);

/*####################### main function #########################*/

int main(void)
{
	struct data q[SIZE];
	int front=0,rare=-1,n=1;
	while(n)
	{
		printf("enter 1 for insert\n");
		printf("enter 2 for delete\n");
		printf("enter 3 for display\n");
		printf("enter 0 to stop\n");
		scanf("%d",&n);
		
		/*########### starting switch case ####################*/
		
		switch(n)
		{
			case 1: inste(q,&rare);
			        break;
			case 2: del(q,&front,&rare);
			        break;
			case 3: disp(q,&front,&rare);
			        break;
			case 0: break;
			
			default: printf("error\n");
			        break;
		}
	}
}

/*################## insert function for a queue ###################*/

void inste(struct data q[],int *r)
{
	struct data v;
	if(*r >= SIZE-1)
	{
		printf("queue is full\n");
		return ;
	}
	else
	{
        (*r)++;
        printf("enter the name\n");
        scanf("%s",v.name);
        printf("name enterde\n");
        printf("enter the priority value\n");
        scanf("%d", &v.prio);
        printf("prio entered\n");
        q[(*r)].prio = v.prio;
        strcpy(q[(*r)].name, v.name);
	}
}

/*#################### deletion function ######################*/

void del(struct data *q,int *f,int *r)
{
	int i;
	if((*r)== -1)
	{
		printf("queue is empty\n");
		return ;
	}
	else
	{
        int position = 0;
		for(i=1;i<=(*r);i++)
		{
			if(q[i].prio < q[position].prio)
			{
				position = i;
			}
			printf("deleted data is :- %s\n%d",q[position].name,q[position].prio);
			for(i = position;i < (*r);i++)
			{
				q[i].prio = q[i+1].prio;
				strcpy(q[i].name,q[i+1].name);
			}
			(*r)--;
		}
	}
}

/*#################### display function ####################*/

void disp(struct data *q,int *f,int *r)
{
    int i;
		for(i=0;i<=(*r);i++)
		{
			printf("priority :- %d\tname :- %s\n",q[i].prio,q[i].name);
		}
}
