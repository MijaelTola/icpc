#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<int> v(n);

    for (int &x: v) 
        cin >> x;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long mn = 1e9;
        for (int j = i; j < n; ++j) {
            mn = min(mn , 1LL * v[j]);
            ans = max(ans, mn * (j - i + 1));
        }
    }

    cout << ans << "\n";
    return 0;
}

