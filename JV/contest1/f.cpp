#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) 
            cin >> v[i];
        
        int ans = 0;
        if(n & 1) {
            for (int i = 0; i < n; i += 2)
                ans ^= v[i];
            cout << ans << "\n";
        } else cout << "0\n";
    }

    return 0;
}

