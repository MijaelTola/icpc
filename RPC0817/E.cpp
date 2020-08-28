#include <bits/stdc++.h>

using namespace std;

long long d[10010];

int n,m,p;
vector<pair<int,int> > G[10010];

long long dijkstra(long long k){
    for (int i = 0; i < 10010; ++i) d[i] = LLONG_MAX;
    
    priority_queue<pair<long long,int> > q;
    q.push(make_pair(0,1));
    d[1] = 0;
    while(!q.empty()){
        int w = -q.top().first;
        int u = q.top().second;
        q.pop();
        
        for (int i = 0; i < (int)G[u].size(); ++i){
            int v = G[u][i].first;
            int ww = G[u][i].second;
            if(d[u] + ww < d[v] and ww <= k){
                d[v] = d[u] + ww;
                q.push(make_pair(-d[v],v));
            }
        }
    }

    return d[n];
}
int main(){
    
    scanf("%d %d %d",&n,&m,&p);
    for (int i = 0;i < m; ++i){
        int x,y,w; 
        scanf("%d %d %d", &x,&y,&w);
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }
    
    long double t = (long double)dijkstra(1e13) * (1.0 + (long double)p/100.0);
    long long a = -1, b = 1e12;

    while(b - a > 1){
        long long mid = (a + b) >> 1;
        long long di = dijkstra(mid);
        if(mid != LLONG_MAX and d[n] <= t) b = mid;
        else a = mid;
    }
    printf("%lld\n",b);
    return 0;
}

