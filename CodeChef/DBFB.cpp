#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int a[100010];
int b[100010];
vector<pair<long long, long long> > fib;

void build() {

    fib.push_back({1,0});
    fib.push_back({0,1});
    for (int i = 2; i < 100010; ++i) {
        pair<long long,long long> da = fib[i - 2];
        pair<long long,long long> db = fib[i - 1];
        fib.push_back({(da.first + db.first) % mod
                , (db.second + da.second) % mod});
    }
}
int main(){
    build();
    int t; cin >> t;
    while(t--) {
        int m,n;
        cin >> m >> n;
        for (int i = 0; i < m; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];

        long long sum1 =0;
        long long sum = 0;

        for (int i = 0; i < m; ++i)
            sum1 = (sum1 + a[i]) % mod;

        for (int i = 0; i < m; ++i)
            sum = (sum + b[i]) % mod;

        long long ans = 0;
        pair<long long, long long> f = fib[n - 1];
        long long l = (f.first * m) % mod;
        long long r = (f.second * m) % mod;
        l = l * sum1;
        r = r * sum;
        long long s = (l + r) % mod;
        ans = (ans + s) % mod;
        cout << ans << "\n";

    }
    return 0;
}

