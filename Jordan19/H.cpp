#include <bits/stdc++.h>

using namespace std;

long double total;
long double n,s;
const long double pi = acos(-1);

long double get(long double mid) {
    long double p = (2 * mid + s) / 2;
    long double cur = sqrt(p * (p - mid) * (p - mid) * (p - s));
    return cur * n;
}
int main() {
    cin >> n >> s;

    long double aa = s / (2 * tan(acos(-1) / n));
    long double per = s * n;
    total = per * aa / 2;

    long double a = 0, b = 1e12;
    

    for (int i = 0; i < 100; ++i) {
        long double mid = (a + b) / 2;
        if(get(mid) >= total) b = mid;
        else a = mid;
    }
    
    printf("%.10Lf\n", pi * b * b);
    return 0;
}

