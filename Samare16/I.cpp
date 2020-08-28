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

vector<int> G[2*100010];
vector<pair<int,int> > node[2*100010];
bool vis[2*100010];

pair<int,pair<int,int> > dfs(int u){
    int sz = 0;
    int edges = G[u].size();
    int nd = u;
    for (int v: G[u]){
        if(!vis[v]){
            vis[v] = true;
            pair<int,pair<int,int> > r = dfs(v);
            if(r.second.first < edges){
                edges = r.second.first;
                nd = r.second.second;
            }
            sz += r.first + 1;
        }
    }
    return {sz,{edges, nd}};
}

int A[2*100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(vis,false,sizeof vis);
    int n,m; cin >> n >> m;
    for (int i = 0; i < 2*100010; ++i) A[i] = 1;
    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y; 
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    int mn = 1e9;
    for (int i = 1; i <= n; ++i){
        if(!vis[i]){
            vis[i] = true;
            pair<int,pair<int,int> > r = dfs(i);
            node[r.first+1].push_back({r.second.first,r.second.second});
            mn = min(mn,r.first+1);
        }
    }
    pair<int,int> ans;
    int mx = 1e9;
    for (int i = 0; i < (int)node[mn].size(); ++i){
        if(node[mn][i].first < mx){
            mx = node[mn][i].first;
            ans = node[mn][i];
        }
    }
    
    for (int v: G[ans.second])
        A[v] = 0;
    A[ans.second] = 0;
    for (int i = 1; i <= n; ++i)
        cout << A[i] << " ";
    return 0;
}

