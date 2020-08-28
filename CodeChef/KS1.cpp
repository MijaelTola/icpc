#include <bits/stdc++.h>

using namespace std;

long long v[100010];
long long b[100010];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        memset(v, 0, sizeof v);
        memset(b, 0, sizeof b);
        map<int, pair<long long, int> > mp;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        
        b[0] = v[0];

        for (int i = 1; i < n; ++i)
            b[i] = b[i - 1] ^ v[i];

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long cur = b[i];
            if(!cur) ans += i;
            int dif = n - i + 1;
            long long total = (dif + 1) * mp[cur].second;
            ans += mp[cur].first - total;

            mp[b[i]].first += dif;
            mp[b[i]].second++;
        }
        cout << ans << "\n";
    }
    return 0;
}

