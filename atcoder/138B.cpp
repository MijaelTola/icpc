#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    long double ans = 0;

    for (int i = 0; i < n; ++i) {
        long double cur;
        cin >> cur;
        ans += (1 / cur);
    }

    printf("%.10Lf\n", 1 / ans);
    return 0;
}

