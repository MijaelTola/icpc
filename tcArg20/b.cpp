#include <bits/stdc++.h>

using namespace std;

int n,m;
long long f[300010];

int main() {
        
    auto build = [] () {
        f[0] = 1;
        for (int i = 1; i < 300010; ++i) 
            f[i] = (i * f[i - 1]) % m;
    };

    cin >> n >> m;

    build();
    
    long long a = (n * f[n]) % m;
    for (int i = 1; i <= n; ++i) {
        long long cur = n - i;
        long long left = f[max(0,n - i - 1)];
        long long per = f[i + 1];
        long long b = (((((per * cur) % m) * cur) % m) * left) % m ;
        a += b;
        a %= m;
    }

    cout << a << "\n";
    return 0;
}
