#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        long long n,m;

        cin >> n >> m;

        vector<long long> v(m);

        for (auto &x: v) {
            cin >> x;
        }


        long long ans =  0;

        for (int i = 1; i < (1 << m); ++i) {
            long long mul = 1;
            int cnt= 0;
            for (int j = 0; j < m; ++j)  {
                if(i & (1 << j)) {
                    cnt++;
                    mul *= v[j];
                }
            }
            
            //cout << cnt << " " << mul << " = " << n / mul << "\n";
            if(cnt & 1) ans += n / mul;
            else ans -= n / mul;
        }
        
        cout << ans << "\n";
    }   
    return 0;
}

