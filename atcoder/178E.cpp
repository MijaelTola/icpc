#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;

struct Point {
    long long x,y;
    Point() {}
    Point(long long _, long long __){
        x = _, y = __;
    }

};

Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

long long cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

long long area(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a);
}

bool operator < (const Point &a, const Point &b) {
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}

long long dis(const Point &a, const Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}


vector<Point> convexHull(vector<Point> v) {
    sort(v.begin(), v.end());
    int n = v.size(), k = 0;
    Point H[2 * n];

    for (int i = 0; i < n; ++i) {
        while(k >= 2 and area(H[k - 2], H[k - 1], v[i]) <= 0) --k;
        H[k++] = v[i];
    }

    for (int i = n - 2, t = k; i >= 0; i--) {
        while(k > t and area(H[k - 2], H[k - 1], v[i]) <= 0) --k;
        H[k++] = v[i];
    }
    return vector<Point> (H, H + k - 1);
}


int n;

int main() {
    vector<Point> pol;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        double x,y;
        scanf("%lf %lf", &x, &y);
        pol.push_back(Point(x,y));
    }

    if(n == 1) {
        puts("0");
        return 0;
    }

    pol = convexHull(pol);
    n = pol.size();
    long long ans = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        while(dis(pol[i],pol[(cur + 1) % n]) > dis(pol[i],pol[cur]))
            cur = (cur + 1) % n;
        ans = max(ans,dis(pol[i],pol[cur]));
    }

    printf("%lld\n", ans);

    return 0;
}

