#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int k;

    while(cin >> k) {
        int ans = 0;
        for (int i = 1; i * i <= k; ++i) {
            if(k % i == 0) {
                int y = k / i;
                int df = max(0,y - i);
                cout << i << " " << k << " " << df << "\n";
                ans += df;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

