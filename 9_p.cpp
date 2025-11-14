// Simple and clean C++ program to draw a triangle and apply:
// a) Scaling b) Translation c) Rotation
// Uses operator overloading for translation (+) and scaling (*)

#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265f

class Point {
public:
    float x, y;
    Point() : x(0), y(0) {}
    Point(float a, float b) : x(a), y(b) {}

    // Translation: p + q shifts point p by q (q holds dx,dy)
    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // Scaling about origin: p * s
    Point operator * (float s) const {
        return Point(x * s, y * s);
    }
};

// draw triangle connecting three points (cast to int for graphics.h)
void drawTriangle(const Point p[3]) {
    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        line((int)round(p[i].x), (int)round(p[i].y),
             (int)round(p[j].x), (int)round(p[j].y));
    }
}

// rotate a point about origin by angle degrees
Point rotatePoint(const Point& p, float angleDeg) {
    float rad = angleDeg * PI / 180.0f;
    float xnew = p.x * cos(rad) - p.y * sin(rad);
    float ynew = p.x * sin(rad) + p.y * cos(rad);
    return Point(xnew, ynew);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); 
    
    Point tri[3] = { Point(280, 220), Point(320, 170), Point(360, 220) };

  
    setcolor(WHITE);
    drawTriangle(tri);
    outtextxy(10, 10, "Original Triangle");
    delay(1000);

    Point center((tri[0].x + tri[1].x + tri[2].x) / 3.0f,
                 (tri[0].y + tri[1].y + tri[2].y) / 3.0f);

    float scaleFactor = 1.4f; 
    Point scaled[3];
    for (int i = 0; i < 3; ++i) {
 
        Point rel = Point(tri[i].x - center.x, tri[i].y - center.y);
        Point s = rel * scaleFactor;
        scaled[i] = Point(s.x + center.x, s.y + center.y);
    }

    cleardevice();
    setcolor(YELLOW);
    drawTriangle(scaled);
    outtextxy(10, 10, "Scaled (1.4x) about center");
    delay(1000);

    // --- Translation ---
    Point translation(80, 40); // move right 80, down 40
    Point moved[3];
    for (int i = 0; i < 3; ++i)
        moved[i] = scaled[i] + translation;

    cleardevice();
    setcolor(GREEN);
    drawTriangle(moved);
    outtextxy(10, 10, "Translated (+80, +40)");
    delay(1000);

    // --- Rotation about the same center (rotate triangle's new center) ---
    // compute new center after translation
    Point newCenter(center.x + translation.x, center.y + translation.y);
    float angleDeg = 30.0f; // gentle rotation to look nice
    Point rotated[3];
    for (int i = 0; i < 3; ++i) {
        Point rel = Point(moved[i].x - newCenter.x, moved[i].y - newCenter.y);
        Point r = rotatePoint(rel, angleDeg);
        rotated[i] = Point(r.x + newCenter.x, r.y + newCenter.y);
    }

    cleardevice();
    setcolor(CYAN);
    drawTriangle(rotated);
    outtextxy(10, 10, "Rotated (30 degrees) about triangle center");
    delay(2000);

    closegraph();
    return 0;
}
