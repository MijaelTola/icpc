#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> G[10010],s;
int in[10010];
int out[10010];
bool vis[10010];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int v: G[u]) 
        dfs(v);
}


int main() {
    
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        out[x]++;
        in[y]++;
        G[x].push_back(y);
    }
    
    dfs(1);
    int cnt = 0;
    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
        cnt += vis[i];
        flag &= in[i] == out[i];
    }

    if(cnt != n or !flag) return cout << "0\n",0;

    cout << "1\n";

    int u = 1;
    vector<int> ans;
    s.push_back(u);
    while(!s.empty()) {
        if(G[u].size()) {
            s.push_back(u);
            int v = G[u].back();
            G[u].pop_back();
            u = v;
        } else {
            ans.push_back(u);
            u = s.back();
            s.pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    for (int x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}

