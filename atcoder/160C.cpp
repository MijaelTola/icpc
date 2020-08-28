#include <bits/stdc++.h>

using namespace std;

int k,n;
int v[200010];
long long b[200010];

int main() {
    
    cin >> k >> n;


    for (int i = 0; i < n; ++i)
        cin >> v[i];


    for (int i = 1; i < n; ++i) 
        b[i] = v[i] - v[i - 1];
    
    b[n] = abs(v[0] + k - v[n - 1]);

    for (int i = 1; i <= n; ++i)
        b[i] += b[i - 1];


    long long ans = 1e14;


    for (int i = 1; i < n; ++i) {
        ans = min(ans, b[n] - abs(v[i % n] - v[(i - 1 + n) % n]));
    }
    ans = min(ans, b[n] - (long long)abs(v[0] + k - v[n - 1]));
    cout << ans <<"\n";

    return 0;
}

