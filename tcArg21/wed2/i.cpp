#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> v[300010];
long long cost[300010];

int main() {

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i].first >> v[i].second;
        long long current = 0;
        for (int i = 0; i < n; ++i) {
            cost[(i + 1) % n] = max(0LL, 1LL * v[(i + 1) % n].first - v[i].second);
            current += cost[(i + 1) % n];
        }
        long long ans = 1e18;
        for (int i = 0; i < n; ++i) 
            ans = min(ans, current - cost[i] + v[i].first);
        cout << ans << "\n";
    }
    return 0;
}

