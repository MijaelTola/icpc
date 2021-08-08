#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int m;
        cin >> m;

        long long ans = 0;
            
        multiset<int> v;
        while(m--) {
            int n;
            cin >> n;

            for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                v.insert(x);
            }
        }

        int cnt = 0;

        for (int x: v) {
            if(x < 0) cnt++;
            else ans += cnt;
        }

        cout << ans << "\n";
    }
    return 0;
}

