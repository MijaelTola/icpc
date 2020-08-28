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
int G[1000][1000];
int B[1000][1000];
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
        for(int i = 1; i <= 800; ++i){
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
        int mn = 1e9;
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
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            cin >> G[i][j+n];
            B[i][j+n] = G[i][j+n];
        }

    for (int i = 1; i <= n; ++i)
        G[0][i] = 1;
    for (int i = 1; i <= m; ++i)
        G[i+n][800] = 1;

    max_flow(0,800);
    for (int i = 1; i <= n; ++i){
        bool flag = false;
        for (int j = n+1; j <= n+m; ++j){
            if(B[i][j] != G[i][j]){ cout << j-n<< " "; flag = true; break;}
        }
        if(!flag) cout << -1 << " ";
    }
    return 0;
}

