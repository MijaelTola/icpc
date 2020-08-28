#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long x,k,d;
    cin >> x >> k >> d;
    
    x = abs(x);
    long long dv = x / d;

    x -= min(dv,k) * d;
    k -= min(dv,k);

    if(k) {
        if(k % 2 == 0) cout << x << "\n";
        else cout << min(abs(x - d), abs(x + d)) << "\n";
    } else cout << x << "\n";
    return 0;
}

