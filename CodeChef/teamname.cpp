#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        vector<int> a(26,0);
        int n;
        cin >> n;
        
        unordered_map<string,int> mp;
        vector<string> v[26];
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            v[s[0] - 'a'].push_back(s);
            mp[s] = 1;
        }

        int ans = 0;
        auto check = [&] (int a, int b) {
            for (auto x: v[a])
                for (auto y: v[b]) {
                    swap(x[0], y[0]);
                    if(mp[x] == 0 and mp[y] == 0) ans += 2;
                    swap(x[0], y[0]);
                }
        };
        
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                if(!v[i].size() or !v[j].size()) continue;
                check(i,j);
            }
        }

        cout << ans << "\n";



    }
    return 0;
}

