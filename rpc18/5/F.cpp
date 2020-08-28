#include <bits/stdc++.h>

using namespace std;

vector<int> v[65];

int main(){

    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        for (int i = 0; i < 60; ++i) v[i].clear();

        int n; cin >> n;

        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            v[x].push_back(i);
        }

        int q; cin >> q;
        while(q--) {
            int x,y; cin >> x >> y;
            x--,y--;
            int ans = 0;
            for (int i = 1; i <= 60; ++i) {
                int l = lower_bound(v[i].begin(),v[i].end(),x) - v[i].begin();
                int r = upper_bound(v[i].begin(),v[i].end(),y) - v[i].begin();
                ans += (r - l) % 2;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

