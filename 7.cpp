// 7.Write C++ program to draw the following pattern.
// Use DDA line and Bresenham‘s circle drawing algorithm. 
// Apply the concept of encapsulation.

#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class DDA{
public:	
	void drawline(int x1 , int y1 , int x2 , int y2){
		float dx = x2-x1;
		float dy = y2-y1;
		float steps = max(abs(dx), abs(dy));
		float xi=dx/steps;
		float yi=dy/steps;
		
		float x = x1;
		float y = y1;
		for(int i = 0 ; i <=steps ; i++){
			putpixel(round(x), round(y), WHITE);
			x=x+xi;
			y+=yi;
		}
	}
};

class Bresenham{
private:
	void drawsymmetry(int xc , int yc , int x , int y){
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc+y,yc+x,WHITE);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc-y,yc-x,WHITE);
	}
public:
	void drawcircle(int xc, int yc, int r){
		int x = 0 ; 
		int y = r;
		int d = 3 - 2 * r;
		drawsymmetry(xc, yc, x, y);
		
		while(y>=x){
			x++;
	
			if(d>0){
					y--;
				d = d + 4 * (x-y) +10;
			}
			else{
				d = d + 4 * x + 6;
				
			}
				drawsymmetry(xc, yc, x, y);
			
		}
	}		
};

int main(){
	int gd = DETECT , gm;
	initgraph(&gd , &gm , "");
	
	DDA line;
	Bresenham c;
int xc = 100;
int yc = 70;
int r1 = 30, r2 = 60;

c.drawcircle(xc, yc, r1);
c.drawcircle(xc, yc, r2);

line.drawline(100,10,150,100);
line.drawline(100,10,50,100);
line.drawline(50,100,150,100);

		getch();
	closegraph();

	return 0;
}

