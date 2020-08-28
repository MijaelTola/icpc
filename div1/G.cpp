#include <bits/stdc++.h>

using namespace std;

int n,a,b;

vector<pair<int,int> > G[2][10010];

int dist[10010];
int who[10010];
int beg[10010];

int main(){
    memset(beg, -1,sizeof beg);
    for (int i = 0; i < 10010; ++i)
        dist[i] = 1e9;

    cin >> n >> a;
    for (int i = 0; i < a; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        G[0][x].push_back(make_pair(y,z));
        G[0][y].push_back(make_pair(x,z));
    }
    cin >> b;
    for (int i = 0; i < b; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        G[1][x].push_back(make_pair(y,z));
        G[1][y].push_back(make_pair(x,z));
    }

    priority_queue<pair<int,pair<int,bool> > > q;
    q.push(make_pair(0,make_pair(0,1)));
    q.push(make_pair(0,make_pair(0,0)));

    dist[0] = 0;

    while(!q.empty()) {
        int u = q.top().second.first;
        bool type = q.top().second.second;
        q.pop();
        for (int i = 0; i < (int)G[type][u].size(); ++i) {
            int v = G[type][u][i].first;
            int w = G[type][u][i].second;
            int d = w + dist[u];
            if(d < dist[v]) {
                dist[v] = d;
                beg[v] = type;
                q.push(make_pair(-d,make_pair(v,type)));
            }
            if(d == dist[v] and type != beg[v]) {
                beg[v] = 2;
                q.push(make_pair(-d,make_pair(v,type)));
            }

        }
    }
    int da = 0, db = 0;
    for (int i = 1; i < n; ++i) {
        if(beg[i] == 0) da++;
        if(beg[i] == 1) db++;
        if(beg[i] == 2) da++,db++;
    }
    cout << da << " " << db << "\n";
    return 0;
}

