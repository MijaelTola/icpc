#include <bits/stdc++.h>

using namespace std;

string a,b;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> a >> b;
    int sz = a.size();
    int ans = 1e9;
    string c = "";
    for (int i = 0; i < sz; ++i) c += '*';

    for (int i = 0; i < (1 << sz); ++i) {
        set<pair<int,string> >st;
        int last = 0;
        string s = "";
        last = 1;
        for (int j = sz - 1, pos = 0; j >= 0; j--, pos++) {
            bool val = (i & (1 << j));
            if(last == val) s += a[pos];
            else {
                if(s.size()) st.insert({-s.size(), s});
                s = a[pos];
            }
            last = val;
        }

        if(s.size()) st.insert({-s.size() ,s});
        string db = b;
        for (auto p: st) {
            int pos = db.find(p.second);
            if(pos == -1) break;
            for (int j = pos; j < pos + (int)p.second.size(); ++j) 
                db[j] = '*';
        }
        if(c == db) 
            ans = min(ans, (int)st.size() - 1);
        
    }
    cout << ans << "\n";
    return 0;
}

