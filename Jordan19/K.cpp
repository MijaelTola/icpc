#include <bits/stdc++.h>

using namespace std;

int v[22];

int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    long long ans = 0;

    for (int i = 0; i < (1 << n); ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) 
            if(i & (1 << j)) cur |= v[j];

        ans += cur;
    }

    cout << ans << "\n";
    return 0;
}

