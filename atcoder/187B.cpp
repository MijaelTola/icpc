#include <bits/stdc++.h>

using namespace std;

int main() {


    int n;
    cin >> n;

    vector<pair<long double, long double> > p;

    for (int i = 0; i < n; ++i) {
        long double x,y;
        cin >> x >> y;
        p.push_back({x,y});
    }

        int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int num = abs(p[j].second - p[i].second);
            int den = abs(p[j].first - p[i].first);
            ans += (num <= den);
        }
    }
    
    cout << ans << "\n";

    return 0;
}

