#include <bits/stdc++.h>

using namespace std;

int main() {
    long double x;
    cin >> x;

    int n; cin >> n;
    
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        long double x,y;
        cin >> x >> y;
        ans += (x * y);
    }
    cout.precision(7);
    cout << fixed << ans * x << "\n";
    return 0;
}

