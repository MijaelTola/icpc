#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;

        int ans = INT_MAX;
        int id = -1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            
            int df = k - x;

            if(df >= 0 and df % x == 0 and df / x < ans) {
                ans = df / x;
                id = x;
            }

        }

        cout << id << "\n";

    }
    return 0;
}

