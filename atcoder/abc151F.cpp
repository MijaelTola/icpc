#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > v;

int main() {

    cin >> n;

    double cx = 0, cy = 0;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        cx += x;
        cy += y;
        v.emplace_back(x,y);
    }
    cx /= n;
    cy /= n;
    
    
    auto dis = [](double a, double b, double x, double y) {
        return sqrt((a - x) * (a - x) + (b - y) * (b - y));
    };
    double ans = 0;

    for (int i = 0; i < n; ++i) {
        double d = dis(v[i].first, v[i].second, cx, cy);
        ans = max(ans, d);
    }
    printf("%.10lf\n", ans);
    return 0;
}

