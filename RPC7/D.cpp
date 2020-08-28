#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;
vector<pair<int,int> > G[110];
int way[110];
bool vis[110];
int d[110];
int n,m;

void dijkstra(int v,int w){
    priority_queue<pair<int,int> > q;
    q.push(make_pair(w,v));
    way[v] = v;
    while(!q.empty()){
        int w = q.top().first;
        int u = q.top().second;
        q.pop();
        for (pair<int,int> v: G[u]){
            if(d[u] + v.second < d[v.first] and !vis[v.first]){
                way[v.first] = u;
                d[v.first] = d[u] + v.second;
                q.push(make_pair(d[v.first],v.first));
            }
        }
    }
}
int main(){
    memset(vis,false,sizeof vis);
    for (int i = 0; i < 110; ++i)
        d[i] = 1e9;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        string x; cin >> x;
        mp[x] = i;
    }
    mp["English"] = 0;
    for (int i = 0; i < m; ++i){
        string x,y; int c;
        cin >> x >> y >> c;
        int dx = mp[x];
        int dy = mp[y];
        G[dx].push_back(make_pair(dy,c));
    }

    vis[0] = 1;
    int ans = 0;
    for (pair<int,int> v: G[0]){
        ans += v.second;
        d[v.first] = 0;
        vis[v.first] = 1;
    }

    for (pair<int,int> v: G[0])
        dijkstra(v.first,v.second);
    
    vector<pair<int,int> > w;
    for (int i = 1; i <= n; ++i){
        int u = i;
        int d = 0;
        cout << u << "\n";
        while(u != way[u]){
            d++;
            u = way[u];
        }
        w.push_back({d,u});
    }
    
    sort(w.rbegin(),w.rend());
    memset(vis,false,sizeof vis);
    for (int i = 1; i <= (int)w.size(); ++i){
        ans += d[w[i].first];
        int u = way[w[i].second];
        vis[u] = 1;
        while(u != way[u]){
            vis[u] = 1;
            u = way[1];
        }
    }

    for (int i = 1; i <= n; ++i)
        if(d[i] == 1e9) return puts("Impossible"),0;
    //ans += d[i];
    cout << ans << "\n";
    return 0;
}

