#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e3 + 10;
const ll inf = 1e15;
int n, m, p; ll g;

ll dist[N][N], min_dist[N][N];
vector<int> G[N];

void dijkstra(int u) {
    for(int i = 0; i < n + 10; i++) min_dist[u][i] = inf;
    min_dist[u][u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, u});
    while(!pq.empty()) {
        int a, b, c;
        tie(c, a) = pq.top();
        pq.pop();
        if(c > min_dist[u][a]) continue;
        for(int i = 0; i < (int)G[a].size(); i++) {
            b = G[a][i];
            if(min_dist[u][a] + dist[a][b] < min_dist[u][b]) {
                min_dist[u][b] = min_dist[u][a] + dist[a][b];
                pq.push({min_dist[u][b], b});
            }
        }
    }
}

int main() {
    while(cin >> n >> m >> p >> g) {
        vector<int> P(p);
        vector<int> vis(p + 1, 0);
        for(int i = 0; i < p; i++) {
            cin >> P[i];
            vis[P[i]] = 1;
        }
        memset(dist, -1LL, sizeof dist);
        for(int i = 0; i < N; i++) G[i].clear();
        while(m--) {
            int a, b; ll c;
            cin >> a >> b >> c;
            if(dist[a][b] == -1LL) {
                dist[a][b] = c;
                dist[b][a] = c;
                G[a].push_back(b);
                G[b].push_back(a);
            }
            dist[a][b] = min(dist[a][b], c);
            dist[b][a] = min(dist[b][a], c);
        }
        vis[1] = 1;

        for(int i = 1; i <= n; i++) {
            if(vis[i]) {
                dijkstra(i);
            }
        }

        ll cost = 1e15;

        for(int i = 1; i <= n; i++) {
            ll p_cost = 0;
            for(int j = 0; j < p; j++) {
                if(min_dist[P[j]][i] + min_dist[1][i] == min_dist[1][P[j]]) {
                    p_cost = p_cost + min(g + min_dist[P[j]][i], min_dist[1][P[j]]);
                } else {
                    p_cost = p_cost + min_dist[1][P[j]];
                }
            }
            cost = min(cost, p_cost);
        }

        cout << cost << "\n";
    }
    return 0;
}

