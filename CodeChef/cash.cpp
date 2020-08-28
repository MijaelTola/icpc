#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        long long ans = 0;
        for (int i = 0; i < n; ++i)  {
            int x; 
            cin >> x;
            ans += x;
        }

        cout << ans % k << "\n";
         
    }
    return 0;
}

