#include <bits/stdc++.h>

using namespace std;

int v[100010];
set<int> s;
map<int,int> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        s.clear();
        mp.clear();
        int n,q;
        cin >> n >> q;

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            mp[v[i]]++;
            if(v[i] == 0) continue;
            s.insert(v[i]);
        }
        
        while(q--) {
            int c;
            cin >> c;
            if(c == 1) {
                int p,x;
                cin >> p >> x;
                p--;
                mp[v[p]]--;
                if(mp[v[p]] == 0) s.erase(v[p]);
                v[p] = x;
                mp[x]++;
                if(x != 0)s.insert(x);
            } else cout << s.size() << "\n";
        }
    }
}
