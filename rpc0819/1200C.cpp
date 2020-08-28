#include <bits/stdc++.h>

using namespace std;

long long dn,dm, gcd;
long long f(long long y) {
    long long a = -1, b = gcd; 
    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(mid * dn >= y) b = mid;
        else a = mid;
    }
    return b;
}

long long r(long long y) {
    long long a = -1, b = gcd; 
    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(mid * dm >= y) b = mid;
        else a = mid;
    }
    return b;
}

int main() {

    long long n,m;
    cin >> n >> m;
    
    gcd = __gcd(n,m);
    
    dn = n / gcd;
    dm = m / gcd;
    int q;
    cin >> q;
    while(q--) {
        long long x,y,a ,b;
        cin >> x >> y >> a >> b;
        long long p1 = (x == 1 ? f(y) : r(y));
        long long p2 = (a == 1 ? f(b) : r(b));
        if(p1 == p2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

