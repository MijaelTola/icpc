#include <bits/stdc++.h>

using namespace std;

int n;
int ix,iy;
vector<pair<int,int> > v;
int dp[1 << 24];
int f(int mask) {
    if(mask == ((1 << n) - 1)) return 0;
    
    int &ans = dp[mask];
    if(ans != -1) return ans;
    ans = 1e9;
    
    auto get = [&] (int a, int b, int x, int y) {
        return (a - x) * (a - x) + (b - y) * (b - y);
    };

    bool flag = 0;
    for (int i = 0; i < n; ++i ) {
        for (int j = i; j < n; ++j)
            if(!(mask & (1 << i)) and !(mask & (1 << j))) {
                flag= 1;
                auto cost = get(ix,iy, v[i].first, v[i].second);
                cost += get(v[i].first, v[i].second, v[j].first, v[j].second);
                cost += get(ix, iy, v[j].first, v[j].second);
                ans = min(ans, f(mask | (1 << i) | (1 << j)) + cost);
            }
        if(flag) break;
    }

    return ans;
}

void r(int mask) {
    if(mask == ((1 << n) - 1)) return;

    int ans = 1e9;
    int di = -1, dj = -1;
    auto get = [&] (int a, int b, int x, int y) {
        return (a - x) * (a - x) + (b - y) * (b - y);
    };
    for (int i = 0; i < n; ++i )
        for (int j = i; j < n; ++j)
            if(!(mask & (1 << i)) and !(mask & (1 << j))) {
                auto cost = get(ix,iy, v[i].first, v[i].second);
                cost += get(v[i].first, v[i].second, v[j].first, v[j].second);
                cost += get(ix, iy, v[j].first, v[j].second);
                if(f(mask | (1 << i) | (1 << j)) + cost < ans) {
                    ans = f(mask | (1 << i) | (1 << j)) + cost;
                    di = i, dj = j;
                }
            }
 
    if(di != dj)
        cout << di + 1 << " " << dj + 1<< " ";
    else cout << di + 1<< " ";
    cout << "0 ";
    r(mask | (1 << di) | (1 << dj));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> ix >> iy;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    cout << f(0) << "\n";
    cout << "0 ";
    r(0);
    cout << "\n";
    return 0;
}

