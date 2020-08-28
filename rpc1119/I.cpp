#include <bits/stdc++.h>

using namespace std;

long long v[1000010];
long long b[1000010];
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        b[i] = v[i] * v[i];
    }
    
    for (int i = 1; i < n; ++i) {
        v[i] += v[i - 1];
        b[i] += b[i - 1];
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) 
        ans = max(ans, b[i] * (v[n - 1] - v[i]));

    cout << ans << "\n";
    return 0;
}

