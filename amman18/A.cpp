#include <bits/stdc++.h>

using namespace std;

vector<pair<int,pair<int,int> > > v;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int m,k;
        cin >> m >> k;

        for (int i = 0; i < m; ++i) {
            int l,r,x;
            cin >> l >> r >> x;
            v.push_back({x,{l,r}});
        }

        sort(v.begin(), v.end());
        
        long long ans = 0;

        for (int i = 0; i < m; ++i) {
            int a = v[i].second.first;
            int b = v[i].second.second;
            long long val = v[i].first;
            long long dis = b - a + 1;
            if(k >= dis) {
                ans += (long long)(dis * val);
                k -= dis;
            } else {
                ans += k * val;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

