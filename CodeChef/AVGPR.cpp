#include <bits/stdc++.h>

using namespace std;

long long v[2010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(v,0,sizeof v);
        set<int> s;
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            v[x + 1000]++;
        }

        long long ans = 0;
        for (int i = 0; i < 2010; ++i) {
             ans += (long long)(v[i] * (v[i] - 1) / 2);
            for (int j = i + 1; j <= 2010; ++j) {
                if(v[i] == 0 or v[j] == 0) continue;
                int di = i - 1000;
                int dj = j - 1000;
                int sum = di + dj;
                if(sum % 2 != 0) continue;
                sum /= 2;
                sum += 1000;
                if(v[sum])  ans += v[i] * v[j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

