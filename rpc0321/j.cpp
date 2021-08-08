#include <bits/stdc++.h>

using namespace std;

int main() {

    long long  r;
    int n;
    cin >> r >> n;

    vector<pair<int,int> > v(n);

    for (auto &p: v)
        cin >> p.first >> p.second;


    auto dis = [&] (int i, int j) {
        int x = v[i].first - v[j].first;
        int y = v[i].second - v[j].second;
        return x * x + y * y;
    };

    int ans = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int mx = dis(i,j);
            if(mx > 2 * r * r) continue;
            int cur = 2;
            for (int k = 0; k < n; ++k) {
                if(k == i or k == j) continue;
                if(dis(i, k) <= mx and dis(j, k) <= mx) cur++;
            }
            ans = max(ans, cur);
        }
    }

    cout << ans << "\n";
    return 0;
}
