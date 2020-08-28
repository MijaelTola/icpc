#include <bits/stdc++.h>

using namespace std;

int d,l;
long long t;
const long double PI = M_PI;
long double distance(double x, double y, double a, double b) {
    return sqrt((x - a) * (x - a) + (y - b)*(y - b));
}
long double find(int bb) {
    long double a = 0;
    long double b = 10;
    for (int i = 0; i < 100; ++i) {
        long double mid = (a + b) / 2;
        long double dis = distance(0.0,0.0,mid,bb);
        if(dis >= d) b = mid;
        else a = mid;
    }
    return b;
}

struct Point {
    long double x,y;
    Point() {}
    Point(long double xx, long double yy) {
        x = xx, y = yy;
    }
};
int main(){
    int t; 
    cin >> t;
    while(t--) {
        cin >> d >> l >> t;
        int x = find(l);
        int y = l;
        Point P1(0,0);
        Point P2(0,d);
        Point P3(x,y);
        long double p12 = distance(P1.x,P1.y,P2.x, P2.y);
        long double p13 = distance(P1.x,P1.y,P3.x, P3.y);
        long double p23 = distance(P2.x,P2.y,P3.x, P3.y);

        long double d1 = acos((p12*p12 + p13*p13 - p23*p23)/ (2 * p12 * p13));
        cout << fmod((d1 * t), (2 * PI)) << "\n";
    }
    return 0;
}

