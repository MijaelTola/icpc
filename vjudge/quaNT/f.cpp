#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        long long r,b,k;
        cin >> r >> b >> k;
        long long g = __gcd(r,b);
        if(r > b) swap(r,b);
        if(r * (k - 1) + g < b) cout << "REBEL\n";
        else cout << "OBEY\n";
    }
    return 0;
}

