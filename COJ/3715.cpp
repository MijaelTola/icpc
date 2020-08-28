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

using namespace std;

typedef long long ll;

vector<pair<int,int> > G[100010];
int d[100010];
int parent[100010];
struct edge{
    int o,d,w;
    edge(){}
    edge(int oo,int dd,int ww){o = oo; d = dd, w = ww;}
    bool operator < (const edge &e){
        return e.w < w;
    }
};

bool cmp(const edge a, const edge b){
    return a.w > b.w;
}
void init(){
        for (int i = 0; i < 100010; ++i)
            parent[i] = i;
}
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x,int y){
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}
vector<edge> e;
void kruskal(){
    init();
    for(int i = 0; i < (int)e.size(); ++i){
        int o = e[i].o;
        int d = e[i].d;
        int w = e[i].w;
 //       cout << w << endl;
        if(find(o) != find(d)){
            Union(o,d);
            G[o].push_back({d,w});
            G[d].push_back({o,w});
        }
    }
}

int main(){
    int n,m; 
    while(cin >> n >> m and n and m){
        for(int i = 0; i < 100010; ++i) G[i].clear();
        e.clear();
       memset(d,-1,sizeof d);
        queue<int> q;
        for (int i = 0; i < m; ++i){
            int x,y,w; cin >> x >> y >> w;
            e.push_back(edge(x,y,w));
        }
        sort(e.begin(),e.end(),cmp);
        kruskal();
        q.push(0);
        d[0] = 1e8;
        int ans= 1e9;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(pair<int,int> v: G[u]){
                if(d[v.first] == -1){
 //                   cout << v.first << endl;
                    d[v.first] = min(d[u],v.second);
                    ans = min(ans,d[v.first]);
                    q.push(v.first);
                }
            }
        }
        bool flag= true;
        for (int i = 0; i < n; ++i)
            if(d[i] == -1){
                flag=false;
                break;
            }
        if(flag) cout << ans << endl;
        else cout << "IMPOSSIBLE"  <<endl;
    }
    return 0;
}

