#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,q;
        cin >> n >> q;

        int last = 0;
        long long ans = 0;
        while(q--) {
            int f,d;
            cin >> f >> d;
            ans += abs(last - f);
            ans += abs(f - d);
            last = d;
        }
        cout << ans << "\n";
    }

    return 0;
}

