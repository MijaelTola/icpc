#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m,p;
    while (cin >> n >> m >> p) {

        vector<pair<int,int> > v;

        for (int i = 0; i < n; ++i) {
            int x;
            char c;
            cin >> x >> c;
            v.push_back({x, c == 'M'});
        }

        sort(v.begin(), v.end());

        int cur = 0;

        for (auto x: v) {
            cur = max(cur, x.first);
            cur += p;
            if(cur <= m) cout << cur << "\n";
            else cout << "Mil disculpas, regrese mañana\n";
        }
    }
    return 0;
}

