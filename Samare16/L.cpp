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
vector<int> G[200010];
vector<int> GT[200010];
int d[200010][2];
int vis[200010];
void bfs(int s,int flag){
    queue<int> q;
    q.push(s);
    d[s][flag] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: GT[u]){
            if(d[v][flag] == -1){
                d[v][flag] = d[u][flag]+1;
                q.push(v);
            }
        }
    }
}

void solve(){
    memset(vis,-1,sizeof vis);
    queue<int> q;
    q.push(0);
    vis[0] = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        for (int v: G[u]){
            if(vis[v]== -1){
                vis[v] = vis[u] +1;
                q.push(v);
            }
        }
    }
}
int main(){
    memset(d,-1,sizeof d);
    int a, b;
    cin >> n >> m >> a >> b;

    for (int i = 0; i < m; ++i){
        int x,y ; cin >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }
    bfs(a,0);
    bfs(b,1);
    solve();/*
    for (int i = 0; i <= n; ++i) cout << d[i][0] << " ";
    cout << endl;
    for (int i = 0; i <= n; ++i) cout << d[i][1] << " ";
    cout << endl;
    for (int i = 0; i <= n; ++i) cout << vis[i] << " ";*/
    int mn = 1e9;
    for (int i = 0; i <= n; ++i){
        if(d[i][0] == -1 or d[i][1] == -1) continue;
        mn = min(mn,vis[i]+d[i][0]+d[i][1]);
    }
    cout << mn <<"\n";
   return 0;
}

