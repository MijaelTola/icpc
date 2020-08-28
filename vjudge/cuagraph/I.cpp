#include <bits/stdc++.h>

using namespace std;

int n,m,s;
vector<int> G[5010];
stack<int> st;
int vis[5010];
int cnt = 0;

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int v: G[u])
        dfs(v);
    st.push(u);
}

void f(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int v: G[u])
        f(v);
}

int main() {
    
    cin >> n >> m >> s;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    
    dfs(s);
    while(!st.empty()) st.pop();
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if(!vis[i]) 
            dfs(i); 

    memset(vis, 0, sizeof vis);
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        if(vis[u]) continue;
        cnt++;
        f(u);
    }
    cout << cnt<< "\n";
    return 0;
}

