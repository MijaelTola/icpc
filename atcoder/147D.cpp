#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int v[300010];

int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    
    long long ans = 0;
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = ((sum ^ v[i]) + ans) % mod;
        sum = (sum + v[i]) % mod;
    }

    cout << ans << "\n";
    return 0;
}

