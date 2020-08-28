#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        long double n,k;
        cin >> n >> k;
        if(fmod(n,k * k) == 0) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

