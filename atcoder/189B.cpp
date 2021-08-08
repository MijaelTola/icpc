#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,k;
    cin >> n >> k;

    vector<pair<long long, long long> > v;
    for (int i = 0; i < n; ++i) {
        long long x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    long long cur = 0;

    for (int i = 0; i < n; ++i) {
        auto [x,y] = v[i];
        cur += x * y;
        if(cur > k * 100)
            return cout << i + 1 << "\n", 0;
    }

    cout << "-1\n";
    return 0;
}

