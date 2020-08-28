#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
int main(){
    
    int t; cin >> t;

    while(t--) {
        long long a,b,n;
        cin >> a >> b >> n;
        long long da = 1;
        long long db = 1;
        long long ans = 1;
        long long dif = ((a - b) + mod)% mod;
        for (int i = 0; i < n; ++i) {
            da = (a * da) % mod;
            db = (b * db) % mod;
            cout << da << " " << db << "\n";
            long long cur = (da + db) % mod;
            //cout << dif << " " << cur << "\n";
        }
        cout << da << " " << db << " " << a - b << " lalala\n";
        cout << __gcd(da + db, a - b) << "\n";;
    }
    return 0;
}

