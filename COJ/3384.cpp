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

using namespace std;

typedef long long ll;

vector<int> G[1010];
bool e[1010][1010];
bool vis[1010];

int dfs2(int u){
    int ans = 0;
    for (int v: G[u]){
        if(!e[u][v] and !e[v][u]){
            e[u][v] = true;
            e[v][u] = true;
            ans += dfs2(v)+1;
        }
    }
    return ans;
}
int dfs(int u){
    int ans = 0;
    for (int v: G[u]){
        if(!vis[v]){
            vis[v] = true;
            ans += dfs(v)+1;
        }
    }
    return ans;
}
int main(){
    memset(vis,false,sizeof vis);
    memset(e,false,sizeof e);
    int n,m,r,e; cin >> n >> m >> r >> e;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1;i <= n; ++i){
        if(!vis[i]){
            vis[i] = true;
            int cities =  dfs(i)+1;
            if(cities == 1) continue;
            int edges = dfs2(i);
            int total = (cities*(cities-1))/2;
            int needededges = total - edges;
            int n1 = needededges*r;
            int n2 = cities*e;
           // cout << edges*r << " "<< cities*e << endl;
            if(n1 < n2) ans += n1;
            else ans += n2;
        }
    }
    cout << ans << endl;
    return 0;
}

