#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int m,n;
        cin >> m >> n;
        vector<int> v(m);
        for (int i = 0; i < m; ++i)
            cin >> v[i];
        map<int,int> mp;

        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            mp[v[i]] += x;
        }
    
        int ans = 1e9;
        for (int i = 1; i <= n; ++i)
            if(mp.count(i)) ans = min(ans, mp[i]);
        cout << ans << "\n";
    }
    
    return 0;
}

