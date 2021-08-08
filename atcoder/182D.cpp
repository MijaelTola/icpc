#include <bits/stdc++.h>

using namespace std;

long long v[200010];
long long mx[200010];

int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    mx[0] = v[0];
    for (int i = 1; i < n; ++i) {
        v[i] += v[i - 1];
        mx[i] = max(v[i], mx[i - 1]);
    }


    long long ans = 0;

    long long cur = 0;

    for (int i = 0; i < n; ++i) {
        long long last = cur;
        cur += v[i];
        ans = max({ans, cur, last + mx[i]});
    }

    cout << ans << "\n";
    return 0;
}

