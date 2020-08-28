#include <bits/stdc++.h>

using namespace std;

long long a[200010];
long long l[200010];
long long r[200010];
int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    l[0] = a[0];

    for (int i = 1; i < n; ++i) 
        l[i] += a[i] + l[i - 1];

    for (int i = n - 1; i >= 0; i--)
        r[i] += a[i] + r[i + 1];
    

    long long ans = LLONG_MAX;

    for (int i = 0; i < n - 1; ++i) {
        ans = min(ans, abs(l[i] - r[i + 1]));
    }
    cout << ans << "\n";

    return 0;
}

