#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > G[510];
int dist[510];
int main(){
    
    int n,m;
    while(scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < 510; ++i) {
            dist[i] = 1e9;
            G[i].clear();
        }

        double a,b;
        scanf("%lf %lf", &a, &b);
        for (int i = 0; i < m; ++i) {
            int x,y,z;
            scanf("%d %d %d", &x, &y, &z);
            G[x].push_back(make_pair(y,z));
            G[y].push_back(make_pair(x,z));
        }
        
        int ini, fin;
        scanf("%d %d", &ini, &fin);

        priority_queue<pair<int,int> > q;
        q.push(make_pair(0,ini));
        dist[ini] = 0;

        while(!q.empty()) {
            int u = q.top().second;
            q.pop();
            for (int i = 0; i < (int)G[u].size(); ++i) {
                int v = G[u][i].first;
                int w = G[u][i].second;
                int d = w + dist[u];
                if(d < dist[v]) {
                    dist[v] = d;
                    q.push(make_pair(-d,v));
                }
            }
        }

        double X = dist[fin];
        double XB = (X * b) / (a + b);
        double t = XB / b;
        printf("%.2lf\n", t);
    }
    return 0;
}

