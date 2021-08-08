#include <bits/stdc++.h>

using namespace std;

vector<tuple<int,int, long long> > v;

int main() {
    
    int n,C;
    cin >> n >> C;


    for (int i = 0; i < n; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    long long current = 0;
    multiset<pair<int,int> > s;
    long long r = 0;
    for (auto [a,b,c]: v) {
        while(!s.empty() and (*s.rbegin()).first < a) {
            current -= (*s.rbegin()).second;
            s.erase(*s.rbegin());
        }
        current += c;
        s.insert({b, c});
        ans += abs(a - r) * min(1LL * C, current);
        r = max(1LL * a, r);
    }

    cout << ans << "\n";

    return 0;
}

