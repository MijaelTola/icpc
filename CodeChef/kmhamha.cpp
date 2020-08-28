#include <bits/stdc++.h>

using namespace std;

set<int> s,st;
map<int,int> match;
map<int, vector<int> > G;
int lim = 1e9;

bool dfs(int u) {
    if(s.count(u)) return 0;
    s.insert(u);
    for (int v: G[u]) {
        if(!match.count(v) or dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }
    return 0;
}

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        G.clear();
        match.clear();
        st.clear();
        s.clear();
        int n;
        cin >> n;
        

        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            st.insert(x);
            G[x].push_back(y + lim);
            G[y + lim].push_back(x);
        }
        
        for (int x: st) {
            if(!match.count(x))
                for (int y: G[x])
                    if(!match.count(y)) {
                        match[x] = y;
                        match[y] = x;
                        break;
                    }
        }

        int ans = 0;

        for (int x: st) {
            if(!match.count(x)) {
                s.clear();
                dfs(x);
            }
        }
    
        for (int x: st)
            if(match.count(x))ans++;
        cout << ans << "\n";


    }
    return 0;
}

