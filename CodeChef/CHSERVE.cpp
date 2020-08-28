#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long x,y,k;
        cin >> x >> y >> k;
        long long p = (x + y) / k;
        if(p & 1LL) puts("COOK");
        else puts("CHEF");
    }
    return 0;
}

