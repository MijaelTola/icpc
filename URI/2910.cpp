#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int , pair<int,int> > > G[10010];
long long dis[10010];
int cost[10010];
int main() {
    
    for (int i = 0; i < 10010; ++i)
        dis[i] = 1e15;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int x,y,l,c;
        scanf("%d %d %d %d", &x, &y, &l, &c);
        G[x].push_back({y,{l,c}});
        G[y].push_back({x,{l,c}});
    }

    priority_queue<pair<long long,int> > q;

    q.push({0,1});
    dis[1] = 0;
    cost[1] = 0;

    while(!q.empty()) {
        int u = q.top().second;
        int w = -q.top().first;
        q.pop();
        
        for (int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i].first;
            int d = G[u][i].second.first;
            int c = G[u][i].second.second;
            if(dis[u] + d < dis[v]) {
                dis[v] = dis[u] + d;
                cost[v] = c;
                q.push({-dis[v], v});
            }
            if(dis[u] + d == dis[v] and c < cost[v]) {
                dis[v] = dis[u] + d;
                cost[v] = c;
                q.push({-dis[v], v});
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += cost[i];
    printf("%lld\n", ans);

    return 0;
}

