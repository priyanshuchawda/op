//8. Write C++ program to draw a concave polygon and fill it with desired color 
//using scan fill algorithm. Apply the concept of inheritance.

#include <iostream>
#include <graphics.h>
#include <algorithm>

using namespace std;

class Point{
public:
	int x;
	int y;
};

class PolygonBase{
public:
		
	int v = 0;
	Point P[21];
	int xmax = INT_MIN;
	int xmin = INT_MAX;
	int ymax = INT_MIN;
	int ymin = INT_MAX;
	
	void readpolygon(){
	
		cout<<"Enter number of vertices : ";
		cin>>v;
		
		cout<<endl;
		if(v<3) exit(0);
		else{
			for(int i = 0 ; i <v ; i++){
				cout<<"x : ";
				cin>>P[i].x;
				cout<<endl;
				cout<<"y : ";
				cin>>P[i].y;
				cout<<endl;
			}
			
	P[v]=P[0];
			
			for(int i = 0 ; i<v ; i++){
				xmax=max(P[i].x,xmax);
				xmin=min(P[i].x,xmin);
				ymax=max(P[i].y,ymax);
				ymin=min(P[i].y,ymin);
			}
		}
	}
	
	void drawpolygon(){
		for(int i = 0 ; i <v ; i++){
			line(P[i].x , P[i].y , P[i+1].x, P[i+1].y);
		}
	}
	
};

class scanfill : public PolygonBase{
	int count ;
	int xi[20];
	void intersections(int y){
		count = 0;
		for(int i = 0 ; i < v ; i++){
			int x1=	P[i].x;
			int x2= P[i+1].x;
			int y1 = P[i].y;
			int y2 = P[i+1].y;
			
			if(y1==y2) continue;
			
			if(y>=min(y1,y2) && y<max(y1,y2)){
				float x = x1 + (float)(y-y1)*(x2-x1)/(y2-y1);
				xi[count++]=x;
			}
		}
	}	
	public:
		void filll(){
			for(int y = ymin ; y<= ymax ; y++){
				intersections(y);
				sort(xi,xi+count);
				
				for(int k = 0 ; k < count ; k+=2){
					line(xi[k],y,xi[k+1],y);
				}
				
			}
		}	
	
};

int main(){
	
	int gd = DETECT , gm;
	initgraph(&gd , &gm ,"");
	scanfill p;
	p.readpolygon();
	p.drawpolygon();
	
	int col;
    cout << "\nEnter fill color (0-15): ";
    cin >> col;
    setcolor(col);

    p.filll();           // fill using scan line

    getch();
    closegraph();
    return 0;
}
