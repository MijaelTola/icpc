#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int,int> > > G[100010];
vector<int> dep;
long long dis[100010];

int main() {
    
    for (int i = 0; i < 100010; ++i)
        dis[i] = 1e16;
    
    int n,m,a,b;
    cin >> n >> m >> a >> b;

    for (int i = 0; i < m; ++i) {
        int x,y,s,t;
        cin >> x >> y >> s >> t;
        G[x].push_back({y, {s, t}});
        G[y].push_back({x, {s, t}});
        dep.push_back(t);
    }

    sort(dep.begin(), dep.end());
    dis[a] = 0;
    
    priority_queue<pair<long long,int> > q;

    q.push({0, a});

    while(!q.empty()) {
        long long w = -q.top().first;
        int u = q.top().second;
        q.pop();

        for (auto tu: G[u]) {
            int v = tu.first;
            int tt = tu.second.first;
            int k = tu.second.second;
            long long dv = w / k;
            if(w % k != 0) dv++;
            long long cost1 = 1LL * dv * k;
            
            if(tt + cost1 < dis[v]) {
                dis[v] = tt + cost1;
                q.push({-dis[v], v});
            }
        }
    }

    if(dis[b] == 1e16) dis[b] = -1;
    cout << dis[b] << "\n";
    
    return 0;
}

