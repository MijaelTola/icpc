#include <bits/stdc++.h>

using namespace std;

int v[]= {100, 20, 10, 5, 1};

int main() {
    
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        ans += n / v[i];
        n %= v[i];
    }
    cout << ans << "\n";
    return 0;
}

