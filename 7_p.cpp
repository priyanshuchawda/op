#include <graphics.h>   // Header file for graphics functions
#include <iostream>
#include <cmath>        // For sin(), cos(), etc.
using namespace std;

#define PI 3.14159265358979323846   // Constant value of p

// -----------------------------
// Class to represent a 2D Point
// -----------------------------
class Point {
public:
    float x, y;

    // Default constructor
    Point() {
        x = y = 0;
    }

    // Parameterized constructor
    Point(float a, float b) {
        x = a;
        y = b;
    }

    // Operator overloading for Translation (+)
    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    // Operator overloading for Subtraction (-)
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    // Operator overloading for Scaling (*)
    Point operator * (float s) const {
        return Point(x * s, y * s);
    }
};

// ----------------------------------------
// Function to draw a triangle using 3 points
// ----------------------------------------
void drawTriangle(const Point pts[]) {
    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3; // Connect last point to first
        line((int)round(pts[i].x), (int)round(pts[i].y),
             (int)round(pts[j].x), (int)round(pts[j].y));
    }
}

// ----------------------------------------------------
// Function to find centroid (average of all 3 vertices)
// ----------------------------------------------------
Point getCentroid(const Point pts[]) {
    float cx = 0, cy = 0;
    for (int i = 0; i < 3; ++i) {
        cx += pts[i].x;
        cy += pts[i].y;
    }
    return Point(cx / 3, cy / 3);
}

// ------------------------------------------------------------
// Function to rotate a point around a given center by some angle
// ------------------------------------------------------------
Point rotateAroundCenter(const Point &p, const Point &center, float angleDeg) {
    float rad = angleDeg * PI / 180.0;   // Convert degrees to radians

    // Step 1: Translate point so that center becomes origin
    float tx = p.x - center.x;
    float ty = p.y - center.y;

    // Step 2: Apply rotation matrix
    float xr = tx * cos(rad) - ty * sin(rad);
    float yr = tx * sin(rad) + ty * cos(rad);

    // Step 3: Translate back to original position
    return Point(xr + center.x, yr + center.y);
}

// -----------------------------
// Main Function
// -----------------------------
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");   // Initialize graphics mode

    // Define original triangle vertices
    Point tri[3] = {
        Point(200, 200),
        Point(250, 150),
        Point(300, 200)
    };

    // -----------------------------
    // 1?? Draw Original Triangle
    // -----------------------------
    setcolor(WHITE);
    drawTriangle(tri);
    outtextxy(10, 10, "Original Triangle");
    delay(1000);
    cleardevice();

    // -----------------------------
    // 2?? Scale Triangle (around centroid)
    // -----------------------------
    float scaleFactor = 1.5;       // Scale by 1.5x
    Point center = getCentroid(tri);
    Point scaled[3];

    for (int i = 0; i < 3; ++i)
        scaled[i] = ((tri[i] - center) * scaleFactor) + center;

    setcolor(YELLOW);
    drawTriangle(scaled);
    outtextxy(10, 10, "Scaled Triangle (1.5x)");
    delay(1000);
    cleardevice();

    // -----------------------------
    // 3?? Translate Triangle
    // -----------------------------
    Point trans(50, 30);           // Translation vector (+50, +30)
    Point translated[3];

    for (int i = 0; i < 3; ++i)
        translated[i] = scaled[i] + trans;

    setcolor(GREEN);
    drawTriangle(translated);
    outtextxy(10, 10, "Translated Triangle (+50, +30)");
    delay(1000);
    cleardevice();

    // -----------------------------
    // 4?? Rotate Triangle (around centroid)
    // -----------------------------
    Point center2 = getCentroid(translated);
    float angle = 45;              // Rotate by 45 degrees
    Point rotated[3];

    for (int i = 0; i < 3; ++i)
        rotated[i] = rotateAroundCenter(translated[i], center2, angle);

    setcolor(CYAN);
    drawTriangle(rotated);
    outtextxy(10, 10, "Rotated Triangle (45 degrees)");
    delay(3000);

    // Close graphics window
    closegraph();
    return 0;
}
