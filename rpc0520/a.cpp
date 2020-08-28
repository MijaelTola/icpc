#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<int,int> > v;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    int ans = 0;

    for (int i = 1; i < n; ++i) {
        int d = v[i].first - v[i - 1].first;
        int t = v[i].second - v[i - 1].second;
        ans = max(ans, t / d);
    }

    cout << ans << "\n";
    return 0;
}

