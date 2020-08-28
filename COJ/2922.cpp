#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x,y;
    Point () {}
    
    Point (double _, double __){
        x = _, y = __;
    }

};

Point operator - (Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.y;
}

vector<Point> v;
int main() {
    bool flag = 1;
    for (int i = 0; i < 6; ++i) {
        double x,y;
        scanf("%lf %lf", &x, &y);
        v.push_back(Point(x,y));
    }
    double areaT = cross(v[4] - v[3],v[5] - v[3]) / 2;
    
    Point CA = v[2] - v[0];
    Point BA = v[1] - v[0];
    CA.x += 1000;
    CA.y += 1000;
    double a = 0, b = 1000;
    for (int i = 0; i < 100; ++i) {
        double mid = (a + b) / 2;
        Point cur = Point(CA.x - mid, CA.y - mid);
        double area = abs(cross(cur,BA));
        if(area >= areaT) b = mid;
        else a = mid;
    }
        
    printf("%lf %lf\n", CA.x - a, CA.y - a);
    return 0;
}

