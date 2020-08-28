#include <bits/stdc++.h>

using namespace std;

int main() {

    int n; cin >> n;
    
    long double f = 1;
    long double ans = 0;
    for (int i = 1; i <= min(11,n); ++i) {
        f *= i;
        if(!(i & 1)) ans += 1 /(f);
        else ans -= 1 /(f);
    }
    cout.precision(8);
    cout << fixed << ans * -1 << "\n";
    return 0;
}

