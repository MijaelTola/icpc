#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    map<string, string> mp;
    set<string> s;

    for (int i = 0; i < n; ++i) {
        string a,b,c;
        cin >> a >> b >> c;
        mp[b] = c;
    }

    int ans = -1;
    for (auto [a,b] : mp) {
        if(s.count(b))continue;
        auto nxt = mp[b];
        int cnt = 1;
        while(nxt != b and !s.count(nxt)) {
            s.insert(nxt);
            cnt++;
            nxt = mp[nxt];
        }

        if(nxt == b) ans = max(ans, cnt);
    }

    if(ans == -1) cout << "No trades possible\n";
    else cout << ans << "\n";
    return 0;
}

