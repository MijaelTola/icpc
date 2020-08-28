#include <bits/stdc++.h>

using namespace std;

int p[5010];
int c[5010];
int vis[5010];

int main() {
    
    int n,k;
    cin >> n >> k;
 
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    
    
    long long ans = -1e15;

    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        int pp = i;
        long long mx = -1e15;
        long long sum = 0;
        int cnt = 0;
        while(!vis[pp]) {
            vis[pp] = 1;
            pp = p[pp];
            sum += c[pp];
            mx = max(mx, sum);
            cnt++;
        }
        
        long long dv = k / cnt;
     
        long long a1 = (dv - 1) * sum;
        long long left = k - (dv - 1) * cnt;
        pp = i;

        long long a2 = -1e15;
        for (int i = 0; i < left; ++i) {
            pp = p[pp];
            a1 += c[pp];
            a2 = max(a2, a1);
        }

        ans = max({ans, a1, mx, a2});
    }

    cout << ans << "\n";
    return 0;
}

