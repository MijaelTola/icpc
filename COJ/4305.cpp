#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        char cur = s[0];
        int ans = 0;
        for (int i = 1; i < (int)s.size(); ++i) {
            if(cur != s[i]) {
                ans++;
                cur = s[i];
            }
        }
        if(cur == 'a') ans++;
        cout << ans << "\n";
    }
    return 0;
}

