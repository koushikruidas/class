#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm, "c:\\tc\\bgi");
	int x0 = 20, y0 = 10 , x1 = 220, y1 = 60;
	int a,b;
	a = x1 - x0;
	b = y1 - y0;

	int d = 2*a+b;
	int ince = 2*b;
	int incne = 2*(b-a);
	int x =x0;
	int y = y0;
	putpixel(x,y,RED);
	while(x<x1)
	{
		if (d<=0)
		{
			d+=ince;
			x++;
		}
		else
		{
			d+=incne;
			x++;
			y++;
		}
		putpixel(x,y,RED);

	}
	getch();
	closegraph();
return 0;

}