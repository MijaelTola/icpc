#include <bits/stdc++.h>

using namespace std;

int scc[500];
bool vis[500];
vector<int> st;
vector<int> G[510];
void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int v: G[u]) {
        if(!vis[v]) dfs(v);
    }
    st.push_back(u);
}

void dfs2(int u, int col) {
    if(scc[u] != -1) return;
    scc[u] = col;
    for (int v:G[u]) {
        if(scc[u] == -1) 
            dfs2(v, col);
    }
}

int lim;

void kosaraju() {

    for (int i = 1; i <= lim; ++i) 
        if(!vis[i]) dfs(i);

    int col = 1;
    while(st.size()) {
        int u = st.back();
        st.pop_back();
        if(scc[u] == -1) {
            dfs2(u, col);
            col++;
        }
    }
}

int main() {

    int t;

    cin >> t;

    while(t--) {
        int n,m,r;
        cin >> n >> m >> r;
        memset(scc, -1, sizeof scc);
        int mid = 100;
        for (int l = 0; l < r; ++l){
            int a,b,x,y;
            cin >> a >> b >> x >> y;
            a += mid;
            b += mid + mid + n;
            x += mid;
            y += mid + mid + n;

            if(a <= x) {
                if(b <= y) {
                    G[b - mid].push_back(x);
                    G[a - mid].push_back(y);
                } else {
                    G[b - mid].push_back(x - mid);
                    G[a].push_back(y);
                }
            } else {
                if(b <= y) {
                    G[a - mid].push_back(y - mid);
                    G[b].push_back(y);
                } else {
                    G[a].push_back(y - mid);
                    G[b].push_back(x - mid);
                }
            }
        }

        kosaraju();

        bool flag = 1;

        for (int i = 0; i < n; ++i) {
            int cur = i + mid;
            flag &= scc[cur] != scc[cur - mid];
        }

        for (int i = 0; i < m; ++i) {
            int cur =  i + mid + mid + n;
            flag &= scc[cur] != scc[cur - mid];
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}

