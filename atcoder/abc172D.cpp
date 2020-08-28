#include <bits/stdc++.h>

using namespace std;

int p[10000010];

int main() {
        
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            p[j]++;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += 1LL * i * (p[i] + 1);
    }
    cout << ans << "\n";
    return 0;
}

