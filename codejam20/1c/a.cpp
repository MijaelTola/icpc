#include <bits/stdc++.h>

using namespace std;

//eson
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    map<char,int> mp;
    mp['E'] = 0;
    mp['S'] = 1;
    mp['W'] = 2;
    mp['N'] = 3;
    int t;
    cin >> t;


    for (int k = 1; k <= t; ++k) {
        int x,y;
        string s;
        cin >> x >> y >> s;
        
        int mn = 1e9;
        for (int i = 0; i < (int)s.size(); ++i) {
            char c = s[i];
            x += dx[mp[c]];
            y += dy[mp[c]];
            
            if(i + 1 >= abs(x) + abs(y)) {
                mn = min(mn, max(i + 1, abs(x) + abs(y)));
            }
        }
        if(mn == 1e9) 
            printf("Case #%d: IMPOSSIBLE\n", k);
        else 
            printf("Case #%d: %d\n", k, mn);
    }
    return 0;
}

