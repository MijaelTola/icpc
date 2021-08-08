#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int> > v(n);

    for (auto &p:v)
        cin >> p.first >> p.second;

    sort(v.begin(), v.end());

    auto dis = [&] (auto a, auto b) {
        return ((a.first - b.first) * (a.first - b.first) + 
                (a.second - b.second) * (a.second - b.second));
    };

    int ans = 0;
    for (int i = 0; i < n - 2; ++i) 
        for (int j = i + 1; j < n - 1; ++j)
            for (int k = j + 1; k < n; ++k) {
                auto a = dis(v[i], v[j]);
                auto b = dis(v[j], v[k]);
                auto c = dis(v[i], v[k]);
                ans += (a + b > c and b + c > a and a + c > b);
            }
    cout << ans << "\n";
    return 0;
}

