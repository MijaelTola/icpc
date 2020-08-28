#include <bits/stdc++.h>

using namespace std;

int n,m,a,b,c;

int parent[1010];
int way[1010];
vector<pair<int, pair<int,int> > > edge;
vector<pair<int,int> > e;
set<pair<int,int> > s;
vector<int> G[1010];
vector<int> G2[1010];
vector<int> ans,path;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int dx = find(x);
    int dy = find(y);
    parent[dx] = dy;
}

void mst() {
    for (int i = 0; i < 1010; ++i) parent[i] = i;

    for (int i = 0; i < (int)edge.size(); ++i) {
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        if(find(u) != find(v)) {
            merge(u,v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(0); 
    way[0] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            if(way[v] == -1) {
                q.push(v);
                way[v] = u;
            }
        }
    }
    int p = n - 1;
    while(way[p] != p) {
        path.push_back(p);
        p = way[p];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); i++) {
        int u = path[i];
        int v = -1;
        int z = -1;
        if(i) z = path[i - 1];
        if(i + 1 < (int)path.size()) v = path[i + 1];
        for (int j = 0; j < (int)G2[u].size(); ++j) {
            int x = G2[u][j];
            if(x == v or x == z) continue;
            s.insert(make_pair(max(u,x), min(u,x)));
        }
    }
}

int main(){
    memset(way, -1, sizeof way);
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        edge.push_back(make_pair(c, make_pair(a,b)));
        e.push_back(make_pair(a,b));
        G2[a].push_back(b);
        G2[b].push_back(a);
    }
    
    sort(edge.rbegin(), edge.rend());
    mst();
    bfs();
    for (int i = 0; i < m; ++i) {
        int u = e[i].first;
        int v = e[i].second;
        if(s.count(make_pair(max(u,v), min(u,v)))) 
            ans.push_back(i);
    }
    
    if((int)ans.size() == 0) return printf("none\n");

    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d", ans[i]);
        if(i + 1 < (int) ans.size() ) 
            printf(" ");
    }
    printf("\n");
    return 0;
}

