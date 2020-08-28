#include <bits/stdc++.h>

using namespace std;

int dp[500010];

int main() {

    int n;
    cin >> n;

    vector<pair<int,int> > v;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    sort(v.begin(), v.end());

    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i], dp[i + 1]);
        int p = upper_bound(v.begin(), v.end(), make_pair(v[i].second, (int)1e9 + 1)) - v.begin();
        dp[i] = max(dp[i], dp[max(p, i)] + 1);
    }

    cout << dp[0] << "\n";
    return 0;
}

