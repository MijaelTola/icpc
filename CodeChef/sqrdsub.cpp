#include <bits/stdc++.h>

using namespace std;

int main() {

    
    int t;
    cin >> t;
    while(t--) {
        
        int n;
        cin >> n;
        vector<int> v(n);

        for (int &x: v)
            cin >> x;

        auto check = [] (auto x) {
            long long a = -1 , b = 1e9 + 1;
            while(b - a > 1) {
                long long mid = (a + b) / 2;
                if(mid * mid >= x) b = mid;
                else a = mid;
            }
            long long left = b * b - x;
            return (long long) sqrt(left) * (long long)sqrt(left) == left;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int p = i;
            long long mul = 1;
            while(p < n) {
                mul *= v[p];
                ans += check(abs(mul));
                p++;
            }
        }
        cout << ans << "\n";

    }
    return 0;
}

