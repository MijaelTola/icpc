#include <bits/stdc++.h>

using namespace std;

int s,e,c,x,y;
vector<int> G[50010];
vector<int> GT[50010];
vector<int> enemies;
stack<int> st;
bool is[500010];
bool vis[50010];
int ans;
void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    ans += !is[u];
    for (int i = 0; i < (int)GT[u].size(); ++i) {
        int v = GT[u][i];
        dfs(v);
    }

}

void dfs2(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i< (int)G[u].size(); ++i) {
        int v = G[u][i];
        dfs2(v);
    }
}

void dfs3(int u) {
    vis[u] = 1;
    for (int i = 0; i < (int) G[u].size(); ++i) {
        int v = G[u][i];
        if(!vis[v]) dfs3(v);
    }
    st.push(u);
}
void toposort() {
    for (int i = 0; i < s; ++i) {
        if(!vis[i]) dfs3(i);
    }
}
int main(){
    memset(is, 0, sizeof is);
    memset(vis, 0, sizeof vis);
    ans = 0;
    scanf("%d %d %d", &s, &e, &c);
    for (int i = 0; i < c; ++i) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        GT[y].push_back(x);
    }
    for (int i = 0; i < e; ++i) {
        scanf("%d", &x);
        is[x] = 1;
        enemies.push_back(x);
    }
    
    toposort();
    memset(vis, 0, sizeof vis);
    
    for (int i = 0; i < (int)enemies.size(); ++i) 
        dfs(enemies[i]);   

    while(!st.empty()) {
        int i = st.top();
        st.pop();
        if(!vis[i]) {
            ans++;
            dfs2(i);
        }
    }

    cout << ans << "\n";
    return 0;
}

