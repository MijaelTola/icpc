#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;
int n;
double base_angle;

struct Point {
    double x,y;
    int w;
    Point() {};
    Point(double _, double __, double ___) {
        x = _, y = __, w = ___;
    }

    double Angle(Point o = Point(0.0, 0.0, 0)){
        double dx = x - o.x;
        double dy = y - o.y;
        double angle = atan2(dy , dx);
        angle -= base_angle;
        if(angle < 0) angle += M_PI * 2;
        return angle;
    }

};

Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y, 0);
}

double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double area(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a);
}

bool operator <(const Point &a, const Point &b) {
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}

bool comp(Point a, Point b){
    return a.Angle() < b.Angle();
}

vector<Point> v;

int f(int pos, int last, int first, int mask) {
    if(pos == n) {
        mask |= (1 << (area(v[last], v[pos - 1], v[first]) > 0 ? 2 : 1));
        if (((mask & (1 << 1)) == 0 or (mask & (1 << 2)) == 0) and mask) return 0;
        return -1e9;
    }

    int ans = -1e9;
    ans = max(ans, f(n, last ,first, mask));

    for (int i = pos; i < n; ++i) {
        int mk = (1 << (area(v[last], v[pos - 1], v[i]) > 0 ? 2 : 1));
        if(mk) ans = max(ans, f(i + 1, pos - 1, first, mk | mask) + v[i].w);
    }
    return ans;
}

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        v.push_back(Point(x, y, w));
    }
    base_angle = v[0].Angle();
    sort(v.begin(), v.end(), comp);

    int ans = -1e9;
    for (int i = 0; i < n; ++i) 
        for (int j = i + 1; j < n; ++j) 
            ans=max(ans, f(j + 1, i, i, 0) + v[i].w + v[j].w);
    cout << ans << "\n";
    return 0;
}

