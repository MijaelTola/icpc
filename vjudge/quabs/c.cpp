#include <bits/stdc++.h>

using namespace std;

int v[100001];

int main() {
    
    int n,d;
    cin >> n >> d;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);

    long long ans = 0;
    
    for (int i = 0; i < n; ++i) {
        int p = upper_bound(v, v + n, v[i] + d) - v - 1;
        long long total = p - i;
        ans += total * (total - 1) / 2;
    }
    
    cout << ans << "\n";
    return 0;
}

