#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n; 

    long long ans1 = 0;
    long double ans2 = 0;
    long long ans3 = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        ans1 += abs(x);
        ans2 += x * x;
        ans3 = max(ans3, abs(x));
    }

    printf("%lld\n", ans1);
    printf("%.15Lf\n", sqrt(ans2));
    printf("%lld\n", ans3);
    return 0;
}

