#include <bits/stdc++.h>

using namespace std;

int v[55];
int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int ans = 0;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            ans += (v[i] * v[j]);
    cout << ans << "\n";

    return 0;
}

