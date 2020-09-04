#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s,t;
    cin >> s >> t;

    int ans = 1e9;

    for (int i = 0; i <= (int)s.size() - (int)t.size(); ++i) {
        int cur = 0;
        for (int j = 0, p = i; j < (int)t.size(); ++j, p++) {
            cur += t[j] != s[p];
        }

        ans = min(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}

