#include <bits/stdc++.h>

using namespace std;

int dis[1000010];
int toDel[1000010];
int cnt[1000010];
int ini[1000010];
int prior[100010];
bool vis[1000010];
vector<int> G[1000010];
vector<int> GT[1000010];
priority_queue<pair<int,int> > q;
stack<int> s;
int ans;

void topo(int u) {
    vis[u] = 1;
    for (int i = 0; i < (int)GT[u].size(); ++i) {
        int v = GT[u][i];
        if(!vis[v])topo(v);
    }
    s.push(u);
}

void topo2(int u) {
    vis[u] = 1;
    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(!vis[v])topo2(v);
    }
    s.push(u);
}


int main() {

    int n,m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        ini[y] = 1;
        GT[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)  
        if(!vis[i]) topo2(i);

    for (int i = 1; i <= n; ++i) {
        dis[i] = -1e9;
        if(!ini[i]) dis[i] = 0;
    }
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        for (int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            if(dis[v] < dis[u] + 1)
                dis[v] = dis[u] + 1;
        }
    }

    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i)
        if(!vis[i]) topo(i);

    while(!s.empty()) {
        int u = s.top();
        s.pop();
        for (int i = 0; i < (int)GT[u].size(); i++) {
            int v = GT[u][i];
            if(dis[v] + 1 == dis[u])cnt[v] += cnt[u] + 1;
        }
    }

    
    for (int i = 1; i <= n; ++i) {
        for (int v: G[i]) {
            if(dis[v] == dis[i] + 1) 
                prior[v] = G[i].size();
        }
    }
    
    for (int i = 1; i <= n; ++i) 
        if(cnt[i] == 0) q.push({prior[i], i});
    
    while(!q.empty()) {
        cout << q.top().second<< " " << q.top().first << "\n";
        q.pop();
    }
    return 0;
}

