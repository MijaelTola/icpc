#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    long long ans = 0;
    long long p = 2;
    for (int i = 0; i < n; ++i) 
        ans += p, p <<= 1LL;
    cout << ans << "\n";
    return 0;
}

