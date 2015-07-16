#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>

void bs(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3, int n, int ic,int sl)
	{
		int i,j;
		float t,tinc,ts,tq,dlt, dlts,dltq,c0,c1,c2,c3;
		float cx[50],cy[50];
		t = 0.0;
		tinc = 1.0/(float)n;
		for(i=0;i<=n;i++)
		{
			ts = t*t;
			tq = ts*t;
			dlt = 1.0 - t;
			dlts = dlt*dlt;
			dltq = dlts*dlt;

			c3 = 0.16667*tq;
			c2 = - 0.5*tq+0.5*(ts+t)+0.16667;
			c0 = 0.16667*dltq;
			c1 = 1.0-(c0+c2+c3);


			cx[i] = c0*x0 + c1*x1 + c2*x2 + c3*x3;
			cy[i] = c0*y0 + c1*y1 + c2*y2 + c3*y3;
			t = t + tinc;
		}
		setcolor(GREEN);
		circle(x0,y0,4);
		circle(x1,y1,4);
		circle(x2,y2,4);
		circle(x3,y3,4);

		setcolor(ic+8);
		line(x0,y0,x1,y1);
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);

		setcolor(ic+1);
		setlinestyle(sl,1,1);

		for(i=0;i<n;i++)
		{
			line(cx[i],cy[i],cx[i+1],cy[i+1]);

			delay(25);
		}

	}

int main()
	{
		int gd = DETECT, gm;
		initgraph(&gd,&gm,"c:\\tc\\bgi");
		int n = 49,m=0,l=0;
		int x0=10,y0=10,x1=60,y1=210,x2=150,y2=250,x3=200,y3=100,x4=300,y4=150,x5=350,y5=250,x6=250,y6=350;
		bs(x0,y0,x1,y1,x2,y2,x3,y3, n, m++,l);
		bs(x1,y1,x2,y2,x3,y3,x4,y4,n,m++,l);
		bs(x2,y2,x3,y3,x4,y4,x5,y5,n,m++,l);
		bs(x3,y3,x4,y4,x5,y5,x6,y6,n,m++,l);

		getch();
		closegraph();

		return 0;
	}