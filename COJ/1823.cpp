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

int G[2500][2500];
int way[2500];
int n,r;
bool bfs(int x,int y){
    memset(way,-1,sizeof way);
    queue<int> q;
    q.push(x);
    way[x] = x;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == y) return true;
        for (int i = 1; i <= n*2; ++i){
            if(way[i] == -1 and G[u][i] > 0){
                way[i] = u;
                q.push(i);
            }
        }
    }
    return false;
}

set<pair<int,int> > e;
int maxflow(int s,int t){
    int ans = 0;
    while(bfs(s,t)){
        int mn = 1e9;
        for (int v = t; v != s; v = way[v]){
            int u = way[v];
            mn = min(mn,G[u][v]);
        }
        for (int v = t; v != s; v = way[v]){
            int u = way[v];
            if(e.count({u,v})) ans += G[u][v];
            G[u][v] -= mn;
            G[v][u] += mn;
        }
    }
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> r;
        memset(G,0,sizeof G);
        for (int i = 1; i <= n; ++i){
            G[i][i+n] = 1e9;
        }
        for (int i = 0; i < r; ++i){
            int x,y,w; cin >> x >> y >> w;
            G[x+n][y] = w;
            e.insert({x+n,y});
        }
        int s; cin >> s;
        while(s--){
            int x; cin >> x;
            G[x][x+n] = 1;
        }
        cout << maxflow(1,2*n) << "\n";
    }
    return 0;
}

