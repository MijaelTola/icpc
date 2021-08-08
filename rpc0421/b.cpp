#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    cin >> n >> k;
    
    vector<string> v(n);

    for (auto &x: v)
        cin >> x;

    int ans = 0;
    for (int i = 0; i < (1 << k); ++i) {
        int mn = 1e9;
        for (auto s: v) {
            int points = 0;
            for (int j = 0; j < (int)s.size(); ++j) {
                char c = '.';
                if((i & (1 << j))) c = 'T';
                else c = 'F';

                if(c == s[j]) points++;
            }
            mn = min(mn, points);
        }
        ans = max(ans, mn);
    }

    cout << ans << "\n";
    return 0;
}

