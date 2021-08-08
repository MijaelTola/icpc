#include <bits/stdc++.h>

using namespace std;

bool vis[1010];
vector<int> G[1010], G2[1010];
map<string, int> mp;
set<string> ans;
string v[1010];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    if(G[u].size() == 1) {
        ans.insert(v[u]);
    }
    for (int v: G[u]) {
        dfs(v);
    }
}

void dfs2(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    ans.insert(v[u]);
    for (int v: G2[u]) {
        dfs2(v);
    }
}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        mp[s] = i;
        v[i] = s;
    }
    
    int t;
    cin >> t;

    while(t--) {
        int m;
        cin >> m;
        cin.ignore();
        string s;
        getline(cin, s);
        int u = mp[s];
        while(m--) {
            getline(cin, s);
            int v = mp[s];
            G[u].push_back(v);
            G2[v].push_back(u);
        }
    }
    
    int q;
    cin >> q;

    while(q--) {
        int c;
        string st;

        cin >> c;
        cin.ignore();
        getline(cin, st);
        ans.clear();
        memset(vis, 0, sizeof vis);

        if(c == 1) {
            dfs2(mp[st]);
        } else {
            dfs(mp[st]);
        }
        
        ans.erase(st);

        if(ans.size()) {
        for (auto x: ans)
            cout << x << "\n";
        } else cout << "None\n";

        if(q) cout << "\n";
    }
    return 0;
}

