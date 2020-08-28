#include <bits/stdc++.h>

using namespace std;

int d[5010][3];
vector<pair<int,int> > G[5010];
void dijkstra(int init, int cur){
    for (int i = 0; i < 5010; ++i) d[i][cur] = 1e9;
    priority_queue<pair<int,int> > q;
    d[init][cur] = 0;
    q.push(make_pair(0,init));
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        for (int i = 0; i < (int)G[u].size(); ++i){
            int v = G[u][i].first;
            int w = G[u][i].second;
            if(d[u][cur] + w < d[v][cur]){
                d[v][cur] = d[u][cur] + w;
                q.push(make_pair(-d[v][cur],v));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int j,b,c,n,s;
    while(cin >> j >> b >> c >> n >> s){
        if(j == -1 and b == -1 and c == -1 and n == -1 and s == -1) break;
        for (int i = 0; i < 5010; ++i) G[i].clear();
        for (int i = 0;i < s; ++i){
            int x,y,w;
            cin >> x >> y >> w;
            G[x].push_back(make_pair(y,w));
            G[y].push_back(make_pair(x,w));
        }
        dijkstra(b,0);
        dijkstra(c,1);
        dijkstra(n,2);
        
        int dn = d[n][0];
        int dc = d[c][0];
        int id = -1;
        int ans = -1;
        for (int i = 1; i <= j; ++i)
            if(d[i][0] + d[i][1] ==  dc and d[i][0] + d[i][2] == dn and d[i][0] > ans)
                ans = d[i][0];
        cout << ans << " " << dc - ans << " " << dn - ans << "\n";
    }
    return 0;
}
