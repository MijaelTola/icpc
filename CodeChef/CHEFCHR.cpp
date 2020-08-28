#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s; cin >> s;
        queue<char> q;
        map<char,int> mp;
        int ans = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            q.push(s[i]);
            mp[s[i]]++;
            if(q.size() > 4) {
                char last = q.front();
                mp[last]--;
                q.pop();
            }
            if(q.size() == 4 and mp['c'] > 0
                    and mp['h'] > 0 and mp['e'] > 0 and mp['f'] > 0) ans++; 

        }
        if(ans) cout << "lovely " << ans << "\n";
        else cout << "normal\n";
    }
    return 0;
}

