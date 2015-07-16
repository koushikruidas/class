#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void circlepoint(int x, int y, int value)
{
	putpixel(x,y,value);
	putpixel(y,x,value);
	putpixel(y,-x,value);
	putpixel(x,-y,value);
	putpixel(-x,-y,value);
	putpixel(-y,-x,value);
	putpixel(-y,x,value);
	putpixel(-x,y,value);
}

void midpointcircle (int radious,int value)
{
	int x=0;
	int y = radious;
	double d = 5.0/4.0 - radious;
	circlepoint(x,y,value);
	while(y>x)
	{
		if(d<0)
		d+=2.0*x+3.0;
		else
		{
			d+=2.0*(x-y)+5.0;
			y--;
		}
		x++;
		circlepoint(x,y,value);
	}

}
int main()
{
	int gd = DETECT, gm;
	int radious = 250;
	int value = YELLOW;
	initgraph(&gd,&gm,"c:\\tc\\BGI");
	midpointcircle(radious,value);
	getch();
	closegraph();
}