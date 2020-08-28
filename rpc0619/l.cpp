#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long x,y,a,b;
        cin >> x >> y >> a >> b;
        vector<long long> v;

        long long da = 1;
        for (int i = 0; i < 63; ++i) {
            long long db = 1;
            for (int j = 0; j < 63; ++j) {
                v.push_back(da + db);
                if(db > 1e18 / y) break;
                db *= y;
            }
            if(da > 1e18 / x) break;
            da *= x;
        }
    
        v.push_back(a - 1);
        v.push_back(b + 1);
        sort(v.begin(), v.end());
        
        long long ans = 0;
        for (int i = 1; i < (int)v.size(); ++i) {
            if(a - 1 <= v[i - 1] and v[i - 1] <= b + 1 
                    and a - 1 <= v[i] and v[i] <= b + 1) {
                ans = max(ans, abs(v[i] - v[i - 1]) - 1);
            }
        }
        
        cout << ans << "\n";

    }
    return 0;
}

