#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
int gd=DETECT,gm,a=50,b=20,c=25,d=30,e=75,f=75;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setcolor(WHITE);
line(50,20,25,30);
line(25,30,75,75);
line(75,75,50,20);
int x1,y1,x2,y2,x3,y3;//SCALING
x1=5*a;
y1=5*b;
x2=5*c;
y2=5*d;
x3=5*e;
y3=5*f;
setcolor(RED);
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);

setcolor(BLUE);//TRANSLATION
line(a+100,b,c+100,d);
line(c+100,d,e+100,f);
line(e+100,f,a+100,b);

// rotation**********
setcolor(GREEN);
int x,y,z,u,v,w;
int an = 60;
int ang = 3.14*an/180;
x = (a*cos(ang))-(b*sin(ang));
y = (a*sin(ang)) + (b*cos(ang));
z = (c*cos(ang)) - (d*sin(ang));
u = (c*sin(ang)) + (d*cos(ang));
v = (e*cos(ang)) - (f*sin(ang));
w =(e*sin(ang)) + (f*cos(ang));
line(x+100,y,z+100,u);
line(z+100,u,v+100,w);
line(v+100,w,x+100,y);

getch();
closegraph();
}
