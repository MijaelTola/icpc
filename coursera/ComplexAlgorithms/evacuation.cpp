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

typedef long long ll;

int n,m; 
int G[10000][10000];
int way[10000];
bool path(int x, int y){
    memset(way,-1,sizeof way);
    queue<int> q;
    q.push(x);
    way[x] = x;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == y) return true;
        for(int i = 1; i <= n; ++i){
            if(way[i] == -1 and G[u][i] > 0){
                way[i] = u;
                q.push(i);
            }
        }
    }
    return false;
}
int max_flow(int s, int t){
    int flow = 0;
    while(path(s,t)){
        int mn = 1e7;
        for (int v = t; v != s; v = way[v]){
            int u = way[v];
            mn = min(mn,G[u][v]);
        }
        flow += mn;
        for (int v = t; v != s; v = way[v]){
            int u = way[v];
            G[u][v] -= mn;
            G[v][u] += mn;
        }
    }
    return flow;
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x,y,w; cin >> x >> y >> w;
        G[x][y] += w; 
    }
    cout << max_flow(1,n) << "\n";
    return 0;
}

