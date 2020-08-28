#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    cin >> n;

    vector<pair<int,int> > v;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({y, x});
    }


    sort(v.rbegin(), v.rend());
    int cur = 1;
    int ans = 0;
    int pos = 0;
    while(cur > 0 and pos < n) {
        ans += v[pos].second;
        cur--;
        cur += v[pos].first;
        pos++;
    }
    
    cout << ans << "\n";
    return 0;
}

