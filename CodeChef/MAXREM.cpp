#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mx = max(v[i], mx);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) 
        ans = max(ans, v[i] % mx);
    cout << ans << "\n";
    return 0;
}

