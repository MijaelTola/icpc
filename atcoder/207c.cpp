#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<pair<int,int> > v;

    for (int i = 0; i < n; ++i) {
        int t,l,r;
        cin >> t >> l >> r;
        if(t == 1) v.emplace_back(l, r);
        if(t == 2) v.emplace_back(l, r - 1);
        if(t == 3) v.emplace_back(l + 1, r);
        if(t == 4) v.emplace_back(l + 1, r - 1);
    }

    auto check = [&] (int x1, int x2, int y1, int y2) {
        return (x1 >= y1 && x1 <= y2) or
            (x2 >= y1 && x2 <= y2) or
            (y1 >= x1 && y1 <= x2) or
            (y2 >= x1 && y2 <= x2);
    };


    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans += check(v[i].first, v[i].second, v[j].first, v[j].second);
        }
    }
    cout << ans << "\n";
    return 0;
}

