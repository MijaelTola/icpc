#include <bits/stdc++.h>

using namespace std;

int main() {
    
    double n;

    cin >> n;

    double ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans += i * (1 / n) ;
    }
    printf("%.15lf\n", ans);
    return 0;
}

