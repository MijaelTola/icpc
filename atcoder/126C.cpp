#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    cin >> n >> k;

    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long cur = i;
        int cnt = 0;
        while(cur < k) cnt++, cur += cur;
        double m = 1;
        while(cnt--) m *= 0.5;
        ans += (m * (1. / n));
    }

    printf("%.10lf\n", ans);
    return 0;
}

