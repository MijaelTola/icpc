#include <bits/stdc++.h>

using namespace std;

int g[300010];

int main() {
    
    int n,p;
    cin >> n >> p;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        g[x]++, g[y]++;
    }
    
    vector<int> v;

    for (int i = 1; i <= n; ++i)
        v.push_back(g[i]);

    sort(v.begin(), v.end());

    long long ans = 0;

    for (int i = 0; i < (int)v.size(); ++i) {
        int x = max(p - v[i], 0);
        int pos = lower_bound(v.begin(), v.end(), x) - v.begin();
        pos = max(pos, i + 1);
        ans += (v.size() - pos);
    }

    cout << ans << "\n";
    return 0;
}

