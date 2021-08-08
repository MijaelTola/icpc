#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[1 << 20][20];
vector<tuple<int,int,int> > points;

long long dis(tuple<int,int,int> p1, tuple<int,int,int> p2) {
    auto [a,b,c] = p1;
    auto [p,q,r] = p2;
    return abs(p - a) + abs(q - b) + max(0, r - c);
};

long long f(int mask, int last) {
    if(mask == (1 << n) - 1) {
        if(last == 0) return 0;
        return dis(points[last], points[0]);
    }

    long long &ans = dp[mask][last];

    if(ans != -1) return ans;
    ans = 1e16;
    for (int i = 0; i < n; ++i) {
        if(!(mask & (1 << i))) {
            ans = min(ans, f(mask | (1 << i), i) + dis(points[last], points[i]));
            ans = min(ans, f(mask | (1 << i), i) + dis(points[last], points[0]) + dis(points[0], points[i]));
        }
    }

    return ans;
}

int main() {
    
    memset(dp, -1, sizeof dp);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        points.push_back({a,b,c});
    }

    cout << f(1, 0) << "\n";

    return 0;
}

