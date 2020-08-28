#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,k;
    cin >> n >> k;
    int ans = 0;
    while(n--) {
        int x;
        cin >> x;
        ans += x >= k;
    }
    cout << ans << "\n";
    return 0;
}

