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

using namespace std;

typedef long long ll;

vector<int> G[10010];
vector<int> GT[10010];
int scc[10010];
bool vis[10010];
stack<int> s;

void dfs(int u){
    for (int v: G[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v);
        }
    }
    s.push(u);
}
void Dfs(int u, int color){
    for (int v:GT[u]){
        if(scc[v] == -1){
            scc[v] = color;
            Dfs(v,color);
        }
    }
}

int kosaraju(int n){
    for (int i = 1; i <= n; ++i){
        if(!vis[i]){
            vis[i] = true;
            dfs(i);
        }
    }
    int color = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(scc[u] == -1){
            scc[u] = ++color;
            Dfs(u,color);
        }
    }
    return color;
}
int main(){
    memset(vis,false,sizeof vis);
    memset(scc,-1,sizeof scc);
    int n,m; cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }
    cout << kosaraju(n) << endl;;
    return 0;
}

