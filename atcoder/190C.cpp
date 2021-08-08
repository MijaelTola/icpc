#include <bits/stdc++.h>

using namespace std;

int v[110];

int main() {
    
    int n,m;
    cin >> n >> m;

    vector<pair<int,int> > con, per;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        con.push_back({x,y});
    }
    
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int x,y;
        cin >> x >> y;
        per.push_back({x,y});
    }

    int ans = 0;

    for (int i = 0; i < (1 << k); ++i) {
        memset(v, 0, sizeof v);
        for (int j = 0; j < k; ++j) {
            if(i & (1 << j)) {
                v[per[j].first] = 1;
            } else {
                v[per[j].second] = 1;
            }
        }

        int cur = 0;
        for (int j = 0; j < m; ++j) {
            if(v[con[j].first] and v[con[j].second]) cur++;
        }

        ans = max(cur, ans);
    }
    cout << ans << "\n";

    return 0;
}

