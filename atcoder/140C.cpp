#include <bits/stdc++.h>

using namespace std;

int n;
int b[110];
int main() {

    cin >> n;

    for (int i = 1; i < n; ++i) cin >> b[i];
    
    b[0] = b[n] = 1e9;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += min(b[i], b[i - 1]);
    cout << ans << "\n";
    
    return 0;
}

