#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<int,int> > v;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({min(x,y), max(x,y)});
    }

    sort(v.begin(), v.end());

    vector<int> ans;

    int cur = v[0].second;
    for (auto p: v) {
        if(p.first <= cur) {
            cur = min(cur, p.second);
        } else {
            ans.push_back(cur);
            cur = p.second;
        }
    }

    ans.push_back(cur);

    cout << ans.size()<< "\n";

    for (auto x: ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}

