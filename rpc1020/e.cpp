#include <bits/stdc++.h>

using namespace std;

#define Vector Point
#define EPS 1e-8

struct Point {
    long double x, y;
    Point(){}
    Point(long double a, long double b) { x = a; y = b; }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator *(const Point &a, long double k) { return Point(a.x*k, a.y*k); }

long double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
long double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

bool operator <(const Point &a, const Point &b) {
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}

bool between(const Point &A, const Point &B, const Point &P) {
    return  P.x + EPS >= min(A.x, B.x) && P.x <= max(A.x, B.x) + EPS &&
            P.y + EPS >= min(A.y, B.y) && P.y <= max(A.y, B.y) + EPS;
}

bool onSegment(const Point &A, const Point &B, const Point &P) {
    return abs(area(A, B, P)) < EPS && between(A, B, P);
}

bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4) {
    long double A1 = area(P3, P4, P1);
    long double A2 = area(P3, P4, P2);
    long double A3 = area(P1, P2, P3);
    long double A4 = area(P1, P2, P4);

    if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) && 
            ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))) 
        return true;

    else if(A1 == 0 && onSegment(P3, P4, P1)) return true;
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true;
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true;
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true;
    else return false;
}

Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D) {
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

long double area2(const vector <Point> &P){
    int n = P.size();
    long double A = 0;
    for(int i=1; i<=n-2; i++)
        A += area(P[0], P[i], P[i+1]);
    return abs(A/2);
}

vector <Point> ConvexHull(vector <Point> P) {
    sort(P.begin(),P.end());
    int n = P.size(),k = 0;
    Point H[2*n];
    
    for(int i=0;i<n;++i){
        while(k>=2 && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    return vector <Point> (H,H+k-1);
}

int main() {

    long double a,b,c,d,x,y,w,z;

    cin >> a >> b >> c >> d >> x >> y >> w >> z;

    Point A = Point(a,b);
    Point B = Point(c,d);

    Point X = Point(x,y);
    Point Y = Point(w,z);

    long double ans = 0;

    if(intersects(A, B, X, Y)) {
        Point C = lineIntersection(A, B, X, Y);

        long double mn = min(B.y, Y.y);

        Point M = Point(-1e9, mn);
        Point N = Point(1e9, mn);

        Point D = lineIntersection(A, B, M, N);
        Point E = lineIntersection(M, N, X, Y);
        
        
        auto v = ConvexHull({E, D, C});
        ans = area2(v);

    }
    
    cout.precision(20);
    cout << fixed << ans << "\n";

    return 0;
}
