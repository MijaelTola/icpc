#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    long long g = 1;
    
    multiset<long long> s;
    
    auto lcm = [&](long long a, long long b) {
        return a * b / gcd(a, b);
    };

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }
    g = *s.begin();
    for (auto x: s) {
        g = lcm(x, g);
    }

    int ans = 0;
    int lim = 1e7;
    while(s.size() > 1 and lim--) {
        auto x = *s.begin();
        s.erase(s.begin());
        auto y = *s.begin();
        if(x == y) {
            s.erase(s.begin());
            s.insert(x + y);
        } else {
            ans++;
            s.insert(x + x);
        }
    }

    if(s.size() == 1) cout << ans << "\n";
    else cout << "-1\n";

    return 0;
}

