#include <bits/stdc++.h>

using namespace std;

const long long fin = 11 * 1000000LL * 1000000LL +  999999 * 1000000LL + 999999 + 1;

int main() {
    int n;
    cin >> n;

    vector<long long> b, v(n + 100);

    for (int i = 0; i < n; ++i) {
        int h,m,s;
        cin >> h >> m >> s;
        long long t = h * 1000000LL * 1000000LL + m * 1000000LL + s;
        b.push_back(t);
    }

    sort(b.begin(), b.end());

   
    for (int i = n - 1; i >= 0; i--) 
        v[i] = fin - b[i];
    

    for (int i = n - 1; i >= 0; i--)
        v[i] += v[i + 1];

    long long dis = 0;
    long long ans = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        long long total = v[i + 1] + b[i] * (n - (i + 1)) + dis;
        long long d = b[i];
        if(i) d -= b[i - 1];
        total += d * i;
        ans = min(ans, total);
        dis += d * i;
    }

    long long m = ans / 1000000;
    long long s = ans % 1000000;
    long long h = m / 1000000;

    m = m % 1000000;
    cout << h << " " << m << " " << s << "\n";

    return 0;
}
