#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<DOS.H>
void bs(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int n,int ic,int sl)
  {
	int i,j;
	float t,tinc,ts,tq,dlt,dlts,dltq,c0,c1,c2,c3;
	float cx[150],cy[150];
	t =0.0 ;
	tinc = 1.0/(float)n;
	for(i=0;i<=n;++i)
	{
		ts = t*t;
		tq = ts*t;
		dlt = 1.0 - t;
		dlts = dlt*dlt;
		dltq = dlts*dlt;
		c0 = dltq;
		c1 = 3.0*dlts*t;
		c2 = 3.0*dlt*ts;
		c3 = tq;
		cx[i] = c0*x0+c1*x1+c2*x2+c3*x3;
		cy[i] = c0*y0+c1*y1+c2*y2+c3*y3;
		t = t + tinc;
	}
	setcolor(ic+7);
	circle(x0,y0,4);
	circle(x1,y1,4);
	circle(x2,y2,4);
	circle(x3,y3,4);
     //	circle(x4,y4,4);

	setcolor(ic+8);

	line(x0,y0,x1,y1);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
     //	line(x3,y3,x4,y4);

	setcolor(ic+1);

	setlinestyle(sl,1,1);

	for(i=0;i<n;++i)
	{
		line(cx[i],cy[i],cx[i+1],cy[i+1]);
		delay(300);
	}
}
int main()
	{
		int gd = DETECT,gm;
		int x0=50,x1=100,x2=400,x3=500,x4=550;
		int y0=400,y1=150,y2=100,y3=300,y4=350;
		int n=30,m=0,l=0;
		initgraph(&gd,&gm,"c:\\TC\\BGI");
		bs(x0,y0,x1,y1,x2,y2,x3,y3,x4,y4,n,++m,l);
		getch();
		closegraph();
		return 0;
	}