#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int p = 0, ne = 0;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if(x > 0) s1 += x, p++;
            else s2 += x, ne++;
        }
        if(ne == 0) {
            cout << n << " " << n << "\n";
            continue;
        } else {
            cout << max(p,ne) << " " << min(p,ne) << "\n";
            continue;
        }
    }
    return 0;
}

