#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
  
    auto modpow = [] (int a, int b) {
        long long x = 1, y = a;
        while(b) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1;
        }
        return x % mod;
    };
 
  

    auto f = [&] ( long  long n) {
         long long vl = ( 333333332LL * modpow (n, 3))% mod;
         long long vr = ( 666666691LL * modpow (n, 5))% mod;
         return ( int ) ((vl + vr) % mod);
    };

    long long n;
    while(cin >> n) {
        cout << f(n) << "\n";
    }
    return 0;
}

