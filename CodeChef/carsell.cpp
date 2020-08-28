#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &x: v) 
            cin >> x;

        sort(v.rbegin(), v.rend());

        long long ans = 0;
        int cnt = 0;
        for (int x: v) {
            ans += max(0, x - cnt);
            cnt++;
        }


        cout << ans % mod << "\n";
        
    }
    return 0;
}

