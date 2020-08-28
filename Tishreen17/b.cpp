#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);
struct Point {
    double x,y;
    Point() {}
    Point(double _, double __) {
        x = _, y = __;
    }
};

Point rotate(Point &a, double angle) {
    double rad = angle * pi / 180;
    double x = a.x * cos(rad) - a.y * sin(rad);
    double y = a.y * cos(rad) + a.x * sin(rad);
    return Point(x,y);
}

vector<Point> pol;

//y = m * (x - x1) + y1
//(y - y1) / 2 + x1 = x
//m = (ya - yb) / (xa - xb)

bool between(double a, double b, double c) {
    return (a <= b and b <= c) or (c <= b and b <= a);
}

bool ver(Point p1, Point p2, Point p3, Point p4, Point p) {
    double m1 = (p1.y - p2.y) / (p1.x - p2.x);
    double y1 = m1 * (p.x - p1.x) + p1.y;
    double x1 = p1.x + (p.y - p1.y) / 2;
    double m2 = (p3.y - p4.y) / (p3.x - p4.x);
    double y2 = m2 * (p.x - p3.x) + p3.y;
    double x2 = p3.x + (p.y - p3.y) / 2;
    return between(y1,p.y,y2);
}

int main() {
    
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m,z;
        scanf("%d%d%d", &n, &m, &z);
        
        for (int i = 0; i < n; ++i) {
            int x,y;
            scanf("%d %d", &x, &y);
            pol.push_back(Point(x,y));
        }
        
        double mid = z / 2.0;
        
        Point p1 = Point(-mid,0);
        Point p2 = Point(mid,0);
        Point p3 = Point(-mid, 100000);
        Point p4 = Point(mid, 100000);
    
        bool flag = 0;
        for (int i = 0; i < 360; ++i) {
            p1 = rotate(p1,i);
            p2 = rotate(p2,i);
            p3 = rotate(p3,i);
            p4 = rotate(p4,i);
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                Point p = pol[j];
                cnt += (ver(p1,p2,p3,p4,p) and ver(p1,p3,p2,p4,p));
            }

            if(cnt >= m) {
                flag = 1;
                break;
            }
        }
        if(!flag) puts("No");
        else puts("Yes");
    }

    return 0;
}

