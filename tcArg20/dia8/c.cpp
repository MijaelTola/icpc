#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        long long t,T,x,c;
        cin >> t >> T >> x >> c;

        long long cur = m * x + c;
        
        if(t + m <= T) {
            ans += c;
            continue;
        } 


        if(t >= T) {
            ans += cur;
            continue;
        }
        
        long long df = T - t;
        long long r = m / df;
        if((m % df) != 0) r++;
        ans += min(cur, r * c);

    }

    cout << ans << "\n";
    return 0;
}

