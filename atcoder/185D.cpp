#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;


    //BRBRR
    int mn = 1e9;
    vector<int> v;
    
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    v.push_back(0);
    v.push_back(n + 1);

    sort(v.begin(), v.end());

    vector<int> b;
    for (int i = 1; i < (int)v.size(); ++i) {
        int d = v[i] - v[i - 1] - 1;
        if(d) {
            mn = min(mn, d);
            b.push_back(d);
        }
    }

    long long ans = 0;
    for (auto x: b) {
        ans += x / mn;
        ans += x % mn != 0;
    }

    cout << ans << "\n";

    return 0;
}

