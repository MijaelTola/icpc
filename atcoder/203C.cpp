#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int main() {
    
    int n;
    long long k;
    cin >> n >> k;
    
    vector<pair<ull, int> > v(n);

    for (auto &p: v)
        cin >> p.first >> p.second;

    sort(v.begin(), v.end());

    bool flag = 1;
    ull ans = 0;
    int pos = 0;

    while(flag) {
        ans += k;
        flag = 0;
        k = 0;
        while(pos < n and v[pos].first <= ans) {
            k += v[pos++].second;
            flag = 1;
        }
    }

    ans += k;

    cout << ans << "\n";


    return 0;
}

