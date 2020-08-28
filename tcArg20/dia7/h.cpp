#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n;
    cin >> n;

    long long cur = n;

    if(n == 1) return cout << "NO\n", 0;
    vector<pair<long long, long long> > v;

    for (long long i = 2; i * i <= n; ++i) {
        int cnt = 0;
        while(n % i == 0) {
             n /= i;
             cnt++;
        }
        if(cnt) {
            v.push_back({i, cnt});
        }
    }

    if(n > 1) v.push_back({n, 1});

    if(v.size() == 1) return cout << "YES\n", 0;

    for (auto p: v) {
        long long po = 1;
        for (int i = 0; i < p.second; ++i)
            po *= p.first;

        long long df = cur / po;
        long long sq = sqrt(df);

        if(sq * sq == df) return cout << "YES\n", 0;
    }
    cout << "NO\n";
    
    return 0;
}

