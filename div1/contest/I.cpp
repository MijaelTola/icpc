#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

struct point {
    point() {}
    double x,y;
    point(double _, double __) {
        x = _;
        y = __;
    }

};

double distance(point &a, point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        double x,y,r;
        //cin >> x >> y >> r;
        scanf("%lf %lf %lf", &x, &y, &r);
        point center = point(x,y);
        point top = point(x, y + r);
        point right = point(x + r, y);
        point newCenter = 
            point((center.x + right.x) / 2, (center.y + top.y) / 2);
        double nr = distance(newCenter, center);
        double areaC = PI * r * r; // main circle
        double segment = areaC / 4; // segment main circle
        double areaCr = PI * nr * nr; // little circle
        double sectorArea = areaCr - segment; // part of the answer
        //triangle newCenter, top, center
        double sectorArea2 = areaCr / 4;
        double triagleArea = (nr * nr) / 2;
        double sector3 = sectorArea2 - triagleArea;
        sector3 *= 2;
        double ans = areaCr - sector3 - sectorArea;

        printf("%.6lf\n",ans);
    }
    return 0;
}

