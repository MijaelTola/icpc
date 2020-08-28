#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;
const double pi = acos(-1);

int n, k = 0;
struct Point {
    double x,y;
    Point() {}
    Point(double _, double __) {
        x = _, y = __;
    }
};

Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

bool operator <(const Point &a, const Point &b) {
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}

double cross (const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double area(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a);
}

void print(Point x) {
    cout << x.x << " " << x.y << "\n";
}
vector<Point> pol;

void convexHull () {
    sort(pol.begin(), pol.end());
    Point H[2 * n];
    for (int i = 0; i < n; ++i) {
        while(k >= 2 and area(H[k - 2], H[k - 1], pol[i]) <= 0) --k;
        H[k++] = pol[i];
    }
    for (int i = n - 2, t = k; i >= 0; --i) {
        while(k > t and area(H[k - 2], H[k - 1], pol[i]) <= 0) --k;
        H[k++] = pol[i];
    }
    pol = vector<Point> (H, H + k - 1);
}

bool ver(Point a, Point b, Point x, Point y) {
    double m1 = (b.y - a.y) / (b.x - a.x);
    double m2 = (x.y - y.y) / (x.x - y.x);
    double angle = atan((m2 - m1)/(1 + m1*m2));
    return angle <= pi;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        pol.push_back(Point(x,y));
    }
    
    convexHull();
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int a = i;
        int b = n;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            int cur = mid % n;
            if(ver(pol[cur], pol[cur + 1], pol[i], pol[i + 1])) b = mid;
            else a = mid;
        }
        int x = b - i;
        ans += (x * (x - 1)) / 2;
    }
    printf("%lld\n", ans);

    return 0;
}

