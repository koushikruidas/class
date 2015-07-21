#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main(void)
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\TC\\bgi");
	int a,b,c,d,e,f,m,n,j,i;
	float s;

	a=100, b=100,c=200,d=100,e=100,f=150;
	printf("enter the scalling factor: ");
	scanf("%f",&s);
	printf("enter the point m: ");
	scanf("%d",&m);
	printf("enter the point n: ");
	scanf("%d",&n);

	cleardevice();
	setcolor(BLUE);

	line(a,b,c,d);
	line(c,d,e,f);
	line(e,f,a,b);

	/* ## scalling ## */
	for(i=0,j=5;i<=2;s=s+0.7,j++,i++)
	{
		line((s*(a-m)+m),(s*(b-n)+n),(s*(c-m)+m),(s*(d-n)+n));
		line((s*(c-m)+m),(s*(d-n)+n),(s*(e-m)+m),(s*(f-n)+n));
		line((s*(e-m)+m),(s*(f-n)+n),(s*(a-m)+m),(s*(b-n)+n));
		setcolor(j++);
	}
	getch();
	closegraph();

}