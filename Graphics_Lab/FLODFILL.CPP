#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void flodfill(int , int);

void main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"c:\\TC\\BGI");
	int x0=30,x1=80;
	int y0=40,y1=80;
	line(x0,y0,x1,y0);
	line(x0,y0,x0,y1);
	line(x0,y1,x1,y1);
	line(x1,y0,x1,y1);

	flodfill(50,50);
	getch();
	closegraph();
}

void flodfill(int x,int y)
{
	if(getpixel(x,y) ==  BLACK)
	{
		putpixel(x,y,GREEN);
		flodfill(x+1,y);
		flodfill(x-1,y);
		flodfill(x,y+1);
		flodfill(x,y-1);

	}
}