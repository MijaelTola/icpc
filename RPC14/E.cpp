#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct edge{
    int s,t;
    long long w;
    edge(){}
    edge(int _s, int _t, long long _w){
        s = _s;
        t = _t;
        w = _w;
    }

    bool operator <(const edge &e) const{
        return w < e.w;
    }
};

int parent[50010];
bool vis[50010];
void init(){
    for (int i = 0; i < 50010; ++i)
        parent[i] = i;
}
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x,int y){
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}

bool same(int x,int y){
    return find(x) == find(y);
}
int n,m,l;
vector<edge> edges;
vector<int> G[50010];
long long kruskal(){
    long long ans = 0LL;
    for (int i = 0;i < (int)edges.size(); ++i){
        int s = edges[i].s;
        int t = edges[i].t;
        int w = edges[i].w;
        if(!same(s,t)){
            Union(s,t);
            ans += w;
        }
    }
    return ans;
}

void dfs(int u){
    for (int v: G[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> l;
    long long total = 0;
    for (int i = 0; i < m; ++i){
        int x,y,w; cin >> x >> y >> w;
        edges.push_back(edge(x,y,w));
        G[x].push_back(y);
        G[y].push_back(x);
        if(i < l)total += w;
    }
    memset(vis,false,sizeof vis);
    int cnt = 0;
    for (int i = 1; i<= n; ++i)
        if(!vis[i]){cnt++; dfs(i);}

    if(cnt > 1) return cout << "impossible\n",0;
    init();
    sort(edges.begin(),edges.end());
    long long ans = kruskal();
    if(total >= ans) cout << "possible\n";
    else cout << "impossible\n";
    return 0;
}

