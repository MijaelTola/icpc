#include <bits/stdc++.h>

using namespace std;

string s;
int vis[60];
int mark[60];
int mark2[60];
int opt[2510][60];
int dp[2510][60];
vector<int> G[2510];



bool dfs(int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    for (int v: G[u]) {
        if(mark[v] == -1 or dfs(mark[v])) {
            mark[u] = v;
            mark[v] = u;
            return 1;
        }
    }
    return 0;
}

int mbm() {
    memset(mark, -1, sizeof mark);
    memset(vis, 0, sizeof vis);
    
    int ans = 0;
    for (int i = 0; i < 26; ++i)
        if(mark[i] == -1) {
            memset(vis, 0, sizeof vis);
            dfs(i);
        }

    for (int i = 0; i < 26; ++i)
        if(mark[i] != -1) ans++;
    return ans;
}

int main() {
    
        int m,a,b,t;
    cin >> m >> a >> b >> t;

    vector<int> da,db;

    for (int i = 0; i < a; ++i) {
        int x;
        cin >> x;
        da.push_back(x);
    }

    for (int i = 0; i < b; ++i) {
        int x;
        cin >> x;
        db.push_back(x);
    }

    for (int i = 0; i < a; ++i) {
        for (int j = i + 1; j < b; ++j) {
            if(abs(da[i] - db[j]) < t) {
               G[i].push_back(j);
               G[j].push_back(i);
            }
        }
    }

    if(mbm() == m) cout << "S\n";
    else cout << "N\n";
    return 0;
}

