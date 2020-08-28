#include <bits/stdc++.h>

using namespace std;

long long a[300010];
long long b[300010];
long long c[300010];

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;


        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
    

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            c[(i + 1) % n] = max(0ll, a[(i + 1) %n] - b[i]);
            sum += c[(i + 1) % n];
        }
        
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            long long total = sum - c[i] + a[i];
            ans = min(total, ans);
        }
        
        cout << ans << "\n";
    }

    return 0;
}

