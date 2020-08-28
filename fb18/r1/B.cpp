#include <bits/stdc++.h>

using namespace std;

vector<int> G[2010];
vector<int> G2[2010];
vector<int> pre,post;
bool vis[2010];
int scc[2010];

void dfs(int u) {
    pre.push_back(u);
    for(int v: G[u]) dfs(v);
    post.push_back(u);
}

void dfs2(int u, int num) {
    if(vis[u]) return;
    vis[u] = 1; scc[u] = num;
    for (int v: G2[u]) dfs2(v, num);
}

void clear() {
    for (int i = 0; i < 2010; ++i) {
        G[i].clear();
        G2[i].clear();
        vis[i] = 0;
        scc[i] = 1;
    }
    pre.clear();
    post.clear();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    int cases = 0;
    while(t--) {
        clear();
        int n,k; cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            int a,b; cin >> a >> b;
            if(a) G[i].push_back(a);
            if(b) G[i].push_back(b);
        }

        dfs(1);

        for (int i = 0; i < (int)pre.size(); ++i) {
            int x = pre[i];
            int y = post[i];
            G2[x].push_back(y);
            G2[y].push_back(x);
        }
        int c = 0;
        for (int i = 1; i <= n; ++i) 
            if(!vis[i]) dfs2(i,++c);
    
        cout << "Case #" << ++cases << ": ";
        if(c < k) {
            cout << "Impossible\n";
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            if(scc[i] <= k) cout << scc[i] << " ";
            else cout << "1 ";
        }
        cout << "\n";
    }
    return 0;
}

