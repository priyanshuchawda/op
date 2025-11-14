// Simple and clean C++ program to draw a triangle and apply:
// a) Scaling b) Translation c) Rotation
// Uses operator overloading for translation (+) and scaling (*)

#include<iostream>
#include <graphics.h>
#include <cmath>
#define pi 3.14

using namespace std;

class Point{
public:
		
	int x , y;
	Point(int a =0 , int b =0 ){
		x=a;
		y=b;
	}	
	
	Point operator + (const Point &p){
		return Point(p.x + x , p.y + y);
	}
	
	Point operator * (float s){
		return Point(s*x , s*y);
	}
};

void drawpolygon(Point p[] , int v){
	for(int i = 0 ; i <v ; i++){
		int j = (i+1)%v;
		line((int) round(p[i].x ),
		(int) ( p[i].y ),
		(int) round( p[j].x) ,
		(int)round( p[j].y));
	}
}

Point rotate(Point p , float ang){
	float rad = ang*pi/180.f;
	float xnew = p.x*cos(rad) - p.y*sin(rad);
	float ynew = p.y*cos(rad) + p.x*sin(rad);
	return Point(xnew , ynew);
}

int main(){
	int gd = DETECT , gm;
	
	initgraph(&gd, &gm, "");
	
	 int v;
    cout << "Enter number of vertices: ";
    cin >> v;

    if (v < 3) {
        cout << "Polygon cannot be formed.\n";
        return 0;
    }
    
    Point p[21];
    for(int i = 0 ; i < v ; i++){
    	cout<<"enter coordinates: ";
    	cin>>p[i].x;
    	cin>>p[i].y;
	}
    setcolor(WHITE);
    drawpolygon(p,v);
    delay(4000);
    
    cleardevice();
    
    float scaleFactor;
    cout << "\nScale factor (e.g., 1.5): ";
    cin >> scaleFactor;

    float dx, dy;
    cout << "Translate dx: ";
    cin >> dx;
    cout << "Translate dy: ";
    cin >> dy;

    float angle;
    cout << "Rotate by degrees: ";
    cin >> angle;
    
    float cx=0;
    float cy=0;
    for(int i = 0 ; i < v ; i++){
    	cx+=p[i].x;
    	cy+=p[i].y;
	}
	cx/=v;
	cy/=v;
	
	
	Point s[21];
	for(int i = 0 ; i <v ; i++){
		Point rel(p[i].x -cx, p[i].y - cy);
		Point t = rel * scaleFactor;
		s[i]= Point(t.x+cx ,t.y +cy );
	}
	cleardevice();
    setcolor(YELLOW);
    drawpolygon(s, v);
    outtextxy(10, 10, "Scaled Polygon");
    delay(1200);
    
     Point T[20];
    for (int i = 0; i < v; i++)
        T[i] =s[i] + Point(dx, dy);

    cleardevice();
    setcolor(GREEN);
    drawpolygon(T, v);
    outtextxy(10, 10, "Translated Polygon");
    delay(1200);

    // ---------- Rotation ----------
    float ncx = cx + dx;
    float ncy = cy + dy;
    Point R[20];

    for (int i = 0; i < v; i++) {
        Point rel(T[i].x - ncx, T[i].y - ncy);
        Point r = rotate(rel, angle);
        R[i] = Point(r.x + ncx, r.y + ncy);
    }

    cleardevice();
    setcolor(CYAN);
    drawpolygon(R, v);
    outtextxy(10, 10, "Rotated Polygon");
    delay(1500);

    closegraph();
    return 0;
}

