#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a,b,x,y;
    cin >> a >>  b >> x >> y;

    long long gcd = __gcd(x,y);
    x /= gcd;
    y /= gcd;

    printf("%lld\n", min(a / x, b / y));
    return 0;
}

