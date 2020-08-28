#include <iostream>
#include <cmath>
using namespace std;

#define Vector Point

const double EPS = 0.00000000001;
struct Point
{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	Point A,B,C,D,E,F,G,H;
    while(cin >> A.x >> A.y >> B.x >> B.y 
            >> C.x >> C.y >> D.x >> D.y >> E.x >> E.y >> F.x >> F.y){
        if(A.x == 0 and A.y == 0 and B.x == 0 
                and B.y == 0 and C.x == 0 and C.y == 0 and D.x == 0 and D.y
                == 0 and E.x == 0 and E.y == 0 and F.x == 0 and F.y == 0) 
            break;
	    C = C+(C-A)*1000;
        A = A+(A-A)*-1000;
        Point a = A, b = C;
	    double ar = abs(cross(D-E,F-E)/2);
	    while(dist(a,b)>EPS){
		    Point mid = (b+a)/2;
		    if(abs(cross(mid-A,B-A)) >= ar) b = mid;
		    else a = mid;
	    }
	
	    G = (b-A);
	    G = G + B;
	    cout.precision(3);
	    cout << fixed << G.x << " " << G.y << " " << b.x << " " << b.y << "\n";
	}
	return 0;
}

// 0 0 5 0 0 5 3 2 7 2 0 4
