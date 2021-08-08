#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {

    cin >> n;
    long long dv = (log10(n) + 1) / 3;

    long double ans = n * dv;
    long double p = 1000;

    while(p < ans) {
        ans -= p;
        ans++;
        p *= 1000;
    }

    cout.precision(0);
    cout << fixed << ans << "\n";

    return 0;
}

