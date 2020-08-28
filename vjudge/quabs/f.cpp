#include <bits/stdc++.h>

using namespace std;

long long a[200001];
long long b[200001];

int main() {
    
    int n,m,ta,tb,k;

    cin >> n >> m >> ta >> tb >> k;

    
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> b[i];

    long long ans = -1;
    
    if(k >= min(n,m) ) return cout << "-1\n", 0;
    for (int i = 0; i <= k; ++i) {
        int p = lower_bound(b, b + m, a[i] + ta) - b;
        if(p + (k - i) < m) ans = max(ans, b[p + (k - i)] + tb);
        else return cout << "-1\n",0;
    }

    cout << ans << "\n";
    return 0;
}

