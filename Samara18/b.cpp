#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-8
const double PI = acos(-1.0);
#define Vector Point

using namespace std;
struct Point
{
    long double x, y;
    Point(){}
    Point(long double a, long double b) { x = a; y = b; }
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
long double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
long double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
long double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

vector< Point > v;


long double area(const vector <Point> &P)
{
    int n = P.size();
    long double A = 0;
    for(int i=1; i<=n-2; i++)
        A += area(P[0], P[i], P[i+1]);
	if(A < EPS) return 1e30;
    return abs(A);
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); 
	int n; cin >> n;
	
	for (int i = 0 ; i < n; ++i) {
		long double x,y; 
		cin >> x >> y;
		v.push_back(Point(x,y));
	}
	//cout << area(v[0],v[1],v[2]) << " test\n";
	
	long double a = 1e50;
	for (int i = 0; i < n; ++i) {
		vector<Point> pp;
		pp.push_back(v[i]);
		pp.push_back(v[(i + 1) % n]);
		pp.push_back(v[(i + 2) % n]);
		a = fmin(a, area(pp));
	}
	cout.precision(0);
	cout << fixed;
	cout << a << "\n";
}
